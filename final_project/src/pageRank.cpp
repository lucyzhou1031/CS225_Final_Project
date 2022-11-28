#include <pageRank.h>

PageRank::PageRank(DataParsing data) {
    A_ = data.getTransitMatrix();
    for (unsigned i = 0; i < A_.size(); i++) {
        std::vector<int> to_push;
        for (unsigned j = 0; j < A_.at(i).size(); j++) {
            to_push.push_back(1);
        }
        ones.push_back(to_push);
    }
}

std::vector<double> PageRank::multiply(std::vector<std::vector<double>> A, std::vector<double> x) {

}
std::vector<double> PageRank::power_iteration(double alpha, double tol, int max_iter) {

}
double PageRank::norm(std::vector<std::vector<double>> a, std::vector<std::vector<double>> a0) {
    
}