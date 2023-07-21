// Try to use vector for lin alg

// #include <Eigen/Dense>
#include <iostream>
#include <random>
#include <vector>

class NN {
  public:
    int num_layers;
    std::vector<int> sizes;
    std::vector<std::vector<std::vector<double>>> biases;
    std::vector<std::vector<std::vector<double>>> weights;

    NN(std::vector<int> architecture) {
        std::random_device dev;
        std::mt19937 rng(dev());
        // std::uniform_int_distribution<std::mt19937::result_type> dist(1, 10);//for a uniform start in weights and biases
        std::normal_distribution<double> dist(0.0, 1.0);

        num_layers = architecture.size();
        sizes = architecture;

        for (int i = 0; i < num_layers; i++) {
            std::vector<double> line_biases;
            std::vector<double> line_weights;
            std::vector<std::vector<double>> matrix_biases;
            std::vector<std::vector<double>> matrix_weights;
            for (int j = 0; j < sizes[i]; j++) {
                for (int k = 0; k < sizes[i + 1]; k++) {
                    line_biases.push_back(dist(rng));
                    line_weights.push_back(dist(rng));
                }
                matrix_biases.push_back(line_biases);
                matrix_weights.push_back(line_weights);
                line_biases.clear();
                line_weights.clear();
            }

            biases.push_back(matrix_biases);
            weights.push_back(matrix_weights);
            matrix_biases.clear();
            matrix_weights.clear();
        }
    }

    double sigmoid_function(double x) {
        return 1. / (1 + exp(-x));
    }

    double logistic_function(double x) {
        return sigmoid_function(x);
    }

    ~NN();
};
