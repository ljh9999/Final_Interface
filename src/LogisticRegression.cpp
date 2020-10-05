//
// Created by ljh on 2020/10/3.
//
#include "LogisticRegression.h"

LogisticRegression::LogisticRegression(int maxIter, float learnRate, float tol = 0.0001) {
    this->maxIter_ = maxIter;
    this->learnRate_ = learnRate;
    this->tol_ = tol;
}

LogisticRegression::LogisticRegression() {
}

LogisticRegression::~LogisticRegression() {
}

DataSet LogisticRegression::loadData(std::string filename) {
    std::ifstream ifile(filename);
    DataSet dataset;
    if (!ifile) {
        std::cout << "can not open file: " << filename << std::endl;
        return dataset;
    }
    std::string line;
    while (getline(ifile, line)) {
        std::vector<std::string> tokens = common::Split(line, ',');
        std::vector<float> feature;
        for (int i = 0; i < tokens.size(); ++i) {
            if (i == tokens.size() - 1) {
                dataset.labels.push_back(atoi(tokens[i].c_str()));
            } else {
                feature.push_back(atof(tokens[i].c_str()));
            }
        }
        dataset.features.push_back(feature);
        dataset.numData += 1;
    }
    dataset.numFeature = dataset.features[0].size();
    return dataset;
}

void LogisticRegression::initWeights(int length) {
    this->weights.push_back(1.0);
    for (int i = 0; i < length; ++i) {
        this->weights.push_back(1.0);
    }
}

std::vector<float> LogisticRegression::oneSampleGrident(std::vector<float> feature, int label) {
    std::vector<float> grident(this->weights.size(), 0.0);
    float predY = predict_proba(feature);
    grident[0] = predY - label;
    for (int i = 0; i < feature.size(); ++i) {
        grident[i + 1] = (predY - label) * feature[i];
    }
    return grident;
}

void LogisticRegression::train(DataSet* dataset, std::string gdType) {
    DataSet* traindata = dataset;
    int dataNum = traindata->numData;
    int featureNum = traindata->numFeature;
    initWeights(featureNum);
    for (int iter = 0; iter < this->maxIter_; ++iter) {
        if (gdType == "gd") {
            std::vector<float> overallGrident(this->weights.size(), 0.0);
            for (int i = 0; i < dataNum; ++i) {
                std::vector<float> tmpGrid = oneSampleGrident(traindata->features[i], traindata->labels[i]);
                for (int j = 0; j < tmpGrid.size(); ++j) {
                    overallGrident[j] += tmpGrid[j];
                }
            }
            for (int i = 0; i < this->weights.size(); ++i) {
                this->weights[i] -= this->learnRate_ * overallGrident[i] / dataNum;
            }
            float loss = 0.0;
            for (int i = 0; i < dataNum; ++i) {
                float predY = predict_proba(traindata->features[i]);
                if (predY < 1e-5) predY = 1e-5;
                if (predY > 1 - 1e-5) predY = 1 - 1e-5;
                loss -= (traindata->labels[i] * log(predY) + (1 - traindata->labels[i]) * log(1 - predY));
            }
            loss /= dataNum;
            std::cout << "iter " << iter << " loss is: " << loss << std::endl;
            if (loss < this->tol_) {
                std::cout << "early stoping for loss is less then tolerance" << std::endl;
                return;
            }
        } else if (gdType == "sgd") {
            std::vector<int> indexes;
            for (int i = 0; i < dataNum; ++i) {
                indexes.push_back(i);
            }
            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
            cout << "seed:" << seed << endl;
            std::shuffle(indexes.begin(), indexes.end(), std::default_random_engine(seed));
            for (int i : indexes) {
                std::vector<float> grident = oneSampleGrident(traindata->features[i], traindata->labels[i]);
                for (int j = 0; j < this->weights.size(); ++j) {
                    this->weights[i] -= this->learnRate_ * grident[i];
                }
                float loss = 0.0;
                for (int n = 0; n < dataNum; ++n) {
                    float predY = predict_proba(traindata->features[n]);
                    if (predY < 1e-5) predY = 1e-5;
                    if (predY > 1 - 1e-5) predY = 1 - 1e-5;
                    loss -= (traindata->labels[n] * log(predY) + (1 - traindata->labels[n]) * log(1 - predY));
                }
                loss /= dataNum;
                std::cout << "iter " << iter << " loss is: " << loss << std::endl;
                if (loss < this->tol_) {
                    std::cout << "early stoping for loss is less then tolerance" << std::endl;
                    return;
                }
            }
        } else {
            std::vector<int> indexes;
            for (int i = 0; i < dataNum; ++i) {
                indexes.push_back(i);
            }
            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
            
            std::shuffle(indexes.begin(), indexes.end(), std::default_random_engine(seed));
            for (int i = 0; i < dataNum; i += 10) {
                std::vector<float> batchGrident(this->weights.size(), 0.0);
                int batchSize = 0;
                for (int j = 0; j < 10; ++j) {
                    int idx = i + j;
                    if (idx >= dataNum) {
                        break;
                    }
                    batchSize += 1;
                    std::vector<float> tmpGrid = oneSampleGrident(traindata->features[idx], traindata->labels[idx]);
                    for (int m = 0; m < tmpGrid.size(); ++m) {
                        batchGrident[m] += tmpGrid[m];
                    }
                }
                for (int n = 0; n < this->weights.size(); ++n) {
                    this->weights[n] -= this->learnRate_ * batchGrident[n] / batchSize;
                }
                float loss = 0.0;
                for (int i = 0; i < dataNum; ++i) {
                    float predY = predict_proba(traindata->features[i]);
                    if (predY < 1e-5) predY = 1e-5;
                    if (predY > 1 - 1e-5) predY = 1 - 1e-5;
                    loss -= (traindata->labels[i] * log(predY) + (1 - traindata->labels[i]) * log(1 - predY));
                }
                loss /= dataNum;
                cout << "seed:" << seed << endl;
                std::cout << "iter " << iter << " loss is: " << loss << std::endl;
                
                if (loss < 0.7)
                {
                    save_weights("model.txt");
                 }
             
                if (loss < this->tol_) {
                    std::cout << "early stoping for loss is less then tolerance" << std::endl;
                    return;
                }
            }
        }
    }
}

std::vector<float> LogisticRegression::getWeight() {
    return this->weights;
}

int LogisticRegression::predict(std::vector<float> feature) {
    float predY = predict_proba(feature);
    if (predY > 0.4) {
        return 1;
    } else {
        return 0;
    }
}

float LogisticRegression::predict2(std::vector<float> feature) {
    float predY = predict_proba(feature);
    return predY;
}

float LogisticRegression::predict_proba(std::vector<float> feature) {
    float summation = this->weights[0];
    for (int i = 0; i < feature.size(); ++i) {
        summation += this->weights[i + 1] * feature[i];
    }
    return common::Sigmoid(summation);
}

float LogisticRegression::score(DataSet* dataset) {
    int rightNum = 0;
    for (int i = 0; i < dataset->numData; ++i) {
        if (predict(dataset->features[i]) == dataset->labels[i]) {
            cout << predict(dataset->features[i]) << endl;
            rightNum++;
        }
//        cout << predict(dataset->features[i]) << endl;
    }
    std::cout << "right number: " << rightNum << std::endl;
    return rightNum * 1.0 / dataset->numData;
}

int LogisticRegression::get_weights() {
    for (auto &i : weights)
    {
        std::cout << i << std::endl;
    }
    return 0;
}

int LogisticRegression::save_weights(const string &sFileName) {
    std::ofstream out (sFileName);

    if (!out)
    {
        cerr << "Can not open the file of " << sFileName << endl;
        return false;
    }

    out << (int)weights.size() << "\n";
    copy(weights.begin(), weights.end(), ostream_iterator<double>(out, "\n"));

    return 0;
}

int LogisticRegression::load_weights(const string &sFileName) {

    model_file = sFileName;
    ifstream in (sFileName);
    if (!in)
    {
        cerr << "Can not open the file of " << sFileName << endl;
        return false;
    }
    weights.clear();
    int iNum = 0;
    in >> iNum;
// weights是个vector，如此加载的权重。
    weights.resize(iNum, 0.0);
    for (int i=0; i<iNum; i++){
        in >> weights[i];
//        cout << "weights:: " << weights[i] << endl;
    }
    return 0;
}
/*
int main(int argc, char* argv[]) {
    if (argc < 7) {
        std::cout << "usage: trainfile, valfile, maxiter, learnrate, tol, gdtype" << std::endl;
        return -1;
    }
    std::string trainFile = std::string(argv[1]);
    std::string valFile = std::string(argv[2]);

    string save_path = "model.txt";

    int maxIter = atoi(argv[3]);
    float learnRate = atof(argv[4]);
    float tol = atof(argv[5]);
    std::string gdType = std::string(argv[6]);
    assert(gdType == "gd" || gdType == "sgd" || gdType == "bachgd");

    LogisticRegression lr(maxIter, learnRate,0.0001);
    DataSet trainData = lr.loadData(trainFile);
    DataSet valData = lr.loadData(valFile);

//    lr.train(&trainData, gdType);
//    lr.save_weights(save_path);
    lr.load_weights("model.txt");
    std::cout << "precision is: " << lr.score(&trainData) << std::endl;

    return 0;
}
*/

