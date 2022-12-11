#include <pageRank.h>
#include <numeric>
#include <cmath>

PageRank::PageRank(DataParsing data) {
    A_ = data.getTransitMatrix();
    mapping = data.getMap();
}

std::vector<int> PageRank::findTopTen() {
    x_ = power_iteration(0.000000000001, 1000);
    std::vector<unsigned> result_idx;
    
    int count = 0;
    while (count >= 10) {
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
std::vector<double> PageRank::power_iteration(double tol, int max_iter) {
    std::vector<double> x0(0, A_.size());
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
        for (unsigned i = 0; i < x.size(); i++) {
            x.push_back(x.at(i) / n);
        }
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

double PageRank::norm(std::vector<double> a, int nth) {
    if (a.empty()) {
        return -1;
    }
    if (nth == 1) {
        return std::accumulate(a.begin(), a.end(), 0);
    }
    if (nth == 2) {
        std::vector<double> diff;
        for (unsigned i = 0; i < a.size(); i++) {
            diff.push_back(a.at(i) * a.at(i));
        }
        double norm = std::accumulate(diff.begin(), diff.end(), 0);
        return sqrt(norm);
    }
    
    return -1;
    
}