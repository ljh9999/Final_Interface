//
// Created by ljh on 2020/10/3.
//

#ifndef LR2_LOGISTICREGRESSION_H
#define LR2_LOGISTICREGRESSION_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <assert.h>
#include "common.h"
#include <random>
#include <chrono>
#include <algorithm>
#include <iterator>

using namespace std;
struct DataSet {
    int numData;
    int numFeature;
    std::vector<std::vector<float> > features;
    std::vector<int> labels;
};


class LogisticRegression {

public:
    LogisticRegression(int max_iter, float learn_rate, float tol);
    LogisticRegression();
    ~LogisticRegression();

    DataSet loadData(std::string filename);

    void initWeights(int length);

    std::vector<float> oneSampleGrident(std::vector<float> feature, int label);

    void train(DataSet* dataset, std::string gdType);

    std::vector<float> getWeight();

    int predict(std::vector<float> feature);
    float predict2(std::vector<float> feature);
    float predict_proba(std::vector<float> feature);

    int get_weights();
    int save_weights(const string & sFileName);
    int load_weights(const string & sFileName);

    float score(DataSet* dataset);

private:
    int maxIter_;
    string model_file;
    float learnRate_;
    float tol_;
    std::vector<float> weights;
};

#endif //LR2_LOGISTICREGRESSION_H
