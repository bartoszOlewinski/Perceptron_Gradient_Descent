#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

static double LEARNING_RATE = 0.05;
static int MINIMUM_CORRECT_GUESSES = 50;
static int NODE_0 = -1;

int main() {
    //weights and their random initializations
    srand(time(NULL));
    double weight0 = (double)rand()/(double)(RAND_MAX/1.0);
    double weight1 = (double)rand()/(double)(RAND_MAX/1.0);
    double weight2 = (double)rand()/(double)(RAND_MAX/1.0);

    double delta_weight0;
    double delta_weight1;
    double delta_weight2;


    int number_of_sets;
    printf("\nWELCOME TO PERCEPTRON TRAINING PROGRAM USING GRADIENT DESCENT\nHow many sets"
           " of data you would like to provide: ");
    scanf("%d", &number_of_sets);
    int target_outputs[number_of_sets];
    int node0s[number_of_sets];
    int node1s[number_of_sets];
    int node2s[number_of_sets];

    //collecting training data from user
    for (int i = 0; i < number_of_sets; i++) {
        //populating node0s array for adjust_weights function
        node0s[i] = NODE_0;

        printf("\nPlease provide set of data number %d\n", i);
        printf("Node1: ");
        scanf("%d", &node1s[i]);
        printf("Node2: ");
        scanf("%d", &node2s[i]);
        printf("Target output for these nodes: ");
        scanf("%d", &target_outputs[i]);
    }

    //a few values used throughout the loop
    int perceptron_output_values[number_of_sets];
    int how_many_correct = 0;
    int how_many_incorrect = 0;
    int is_done = 0;
    do {
        delta_weight0 = 0;
        delta_weight1 = 0;
        delta_weight2 = 0;

        for (int i = 0; i < number_of_sets; i++) {
            //computing outputs from perceptron
            perceptron_output_values[i] = perceptron_output(weight0, weight1, weight2, NODE_0, node1s[i], node2s[i]);
            printf("\n----\nUsing weights: %f, %f, %f, the perceptron output is %d.\n"
                   "Correct answer is %d.", weight0, weight1, weight2, perceptron_output_values[i], target_outputs[i]);
            if (perceptron_output_values[i] == target_outputs[i]) {
                how_many_correct++;
                printf("\nPerceptron guessed correctly.\n");
            } else {
                how_many_incorrect++;
                printf("\nPerceptron guessed incorrectly.\n");
            }

            //adjusting delta weights
            delta_weight0 = (LEARNING_RATE * (target_outputs[i] - perceptron_output_values[i]) * NODE_0);
            delta_weight1 = (LEARNING_RATE * (target_outputs[i] - perceptron_output_values[i]) * node1s[i]);
            delta_weight2 = (LEARNING_RATE * (target_outputs[i] - perceptron_output_values[i]) * node2s[i]);

            delta_weight0 += adjust_weight(LEARNING_RATE, node0s, target_outputs, perceptron_output_values, number_of_sets);
            delta_weight1 += adjust_weight(LEARNING_RATE, node1s, target_outputs, perceptron_output_values, number_of_sets);
            delta_weight2 += adjust_weight(LEARNING_RATE, node2s, target_outputs, perceptron_output_values, number_of_sets);
        }

        //adjusting actual weights
        weight0 += delta_weight0;
        weight1 += delta_weight1;
        weight2 += delta_weight2;

        if (how_many_correct > MINIMUM_CORRECT_GUESSES) {
            is_done = 1;
        }
    } while(!is_done);

    printf("\n--------\nThis perceptron went through %d datasets and guessed:\n"
           "incorrectly: %d\ncorrectly: %d", how_many_correct+how_many_incorrect, how_many_incorrect, how_many_correct);



    return 0;
}
