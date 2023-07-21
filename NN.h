#include <Eigen/Dense>
#include <iostream>
#include <random>
#include <vector>

using Eigen::MatrixXd;
using Eigen::VectorXd;

class NN {
  public:
    int num_layers;
    std::vector<int> sizes;

    std::vector<MatrixXd> biases;
    std::vector<VectorXd> weights;

    NN(std::vector<int> architecture) {
        std::random_device dev;
        std::mt19937 rng(dev());
        // std::uniform_int_distribution<std::mt19937::result_type> dist(1, 10);//for a uniform start in weights and biases
        std::normal_distribution<double> dist(0.0, 1.0);

        num_layers = architecture.size();
        sizes = architecture;

        for (int i = 1; i < num_layers; i++) {
            VectorXd b = VectorXd::Random(sizes.at(i));
            biases.push_back(b);
        }

        for (int i = 0; i < num_layers - 1; i++) {
            MatrixXd m = MatrixXd::Random(sizes.at(i), sizes.at(i + 1));
            weights.push_back(m);
        }
    }

    double sigmoid_function(double x) {
        return 1. / (1 + exp(-x));
    }

    double logistic_function(double x) {
        return sigmoid_function(x);
    }

    void fed_foward() {
    }

    ~NN();
};
