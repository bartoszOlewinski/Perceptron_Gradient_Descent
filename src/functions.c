#include <stdlib.h>
#include "functions.h"

double adjust_weight(double learning_rate, int input_nodes[], int target_outputs[], int computed_output[], int how_many_sets) {
    double gradient_descent_sum = 0;
    for (int i = 0; i < how_many_sets; i++) {
        gradient_descent_sum += (target_outputs[i] - computed_output[i]) * input_nodes[i];
    }
    gradient_descent_sum *= learning_rate;

    return gradient_descent_sum;
}

int perceptron_output(double weight0, double weight1, double weight2,
                      int node0, int node1, int node2) {
    if (((double) node0 * weight0) + ((double) node1 * weight1) + ((double) node2 * weight2) > 0)
        return 1;
    else return 0;

}
