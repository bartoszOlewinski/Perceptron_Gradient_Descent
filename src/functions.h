#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

//adjusting weights accordring to gradient descent
double adjust_weight(double learning_rate, int input_nodes[], int target_outputs[], int computed_output[], int how_many_sets);

//computing linear output out of perceptron
int perceptron_output(double weight0, double weight1, double weight2,
                      int node0, int node1, int node2);

#endif