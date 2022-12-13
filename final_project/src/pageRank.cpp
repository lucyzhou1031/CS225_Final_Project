#include <pageRank.h>
#include <numeric>
#include <cmath>

/**
 * @brief Construct a new Page Rank:: Page Rank object
 * 
 * @param data a DataParsing class input
 */
PageRank::PageRank(DataParsing data) {
    A_ = data.getTransitMatrix();
    mapping = data.getMap();
}

/**
 * @brief find the top ten websites as vector (ordered)
 * 
 * @return std::vector<int> 
 */
std::vector<int> PageRank::findTopTen() {
    x_ = power_iteration(0.000000000001, 1000);
    int size = 10;
    if (x_.size() < 10) {
        size = x_.size();
    }
    std::vector<unsigned> result_idx;
    
    int count = 0;
    while (count < size) {
        double max = -1;
        double max_idx = -1;
        for (unsigned i = 0; i < x_.size(); i++) {
            if (x_.at(i) > max) {
                max = x_.at(i);
                max_idx = i;
            }
        }
        result_idx.push_back(max_idx);
        x_.at(max_idx) = -1;
        count++;
    }
    std::vector<int> top_ten;
    for (unsigned i = 0; i < result_idx.size(); i++) {
        for (auto it = mapping.begin(); it != mapping.end(); it++) {
            if (it -> second == result_idx.at(i)) {
                top_ten.push_back(it -> first);
            }
        }
    }
    return top_ten;
}

/**
 * @brief do a multiplication of two matrixes
 * 
 * @param A matrix to be multiplied
 * @param x multiplier matrix
 * @return std::vector<double> 
 */
std::vector<double> PageRank::multiply(std::vector<std::vector<double>> A, std::vector<double> x) {
    std::vector<double> to_return;
    for (unsigned i = 0; i < A.size(); i++) {
        double sum = 0;
        for (unsigned j = 0; j < A.at(i).size(); j++) {
            sum += A.at(i).at(j) * x.at(j);
        }
        to_return.push_back(sum);
    }
    return to_return;
}

/**
 * @brief proceed iteration given maximun iteration and tolerance
 * 
 * @param tol the tolerance of iteration
 * @param max_iter the maximun num of designed iteration
 * @return std::vector<double> 
 */

std::vector<double> PageRank::power_iteration(double tol, int max_iter) {
    std::vector<double> x0(A_.size(), 0);
    x0.at(0) = 1;
    double n = norm(x0, 1);
    std::vector<double> x;
    for (unsigned i = 0; i < x0.size(); i++) {
        
        x.push_back(x0.at(i) / n);
    }
    for (int i = 0; i < max_iter; i++) {
        x0 = x;
        x = multiply(A_, x);
        n = norm(x, 1);
        std::vector<double> temp;
        for (unsigned i = 0; i < x.size(); i++) {
            temp.push_back(x.at(i) / n);
        }
        x = temp;
        std::vector<double> diff;
        for (unsigned roll = 0; roll < x.size(); roll++) {
            diff.push_back(x.at(roll) - x0.at(roll));
        }
        if (norm(diff, 2) < tol) {
            break;
        }
    }
    return x;

}

/**
 * @brief noralize the matrix with desired times
 * 
 * @param a input matrix
 * @param nth desired time of normalization
 * @return double 
 */
double PageRank::norm(std::vector<double> a, int nth) {
    if (a.empty()) {
        return -1;
    }
    if (nth == 1) {
        double sum = 0;
        for (unsigned i = 0; i < a.size(); i++) {
            sum += std::abs(a.at(i));
        }
        return sum;
    }
    if (nth == 2) {
        std::vector<double> diff;
        for (unsigned i = 0; i < a.size(); i++) {
            diff.push_back(a.at(i) * a.at(i));
        }
        double norm = 0;
        for (unsigned i = 0; i < diff.size(); i++) {
            norm += diff.at(i);
        }
        return sqrt(norm);
    }
    
    return -1;
    
}