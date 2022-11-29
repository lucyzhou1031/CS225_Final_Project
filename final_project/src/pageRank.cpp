// #include <pageRank.h>
// #include <numeric>
// #include <cmath>

// PageRank::PageRank(DataParsing data) {
//     A_ = data.getTransitMatrix();
//     for (unsigned i = 0; i < A_.size(); i++) {
//         std::vector<int> to_push;
//         for (unsigned j = 0; j < A_.at(i).size(); j++) {
//             to_push.push_back(1);
//         }
//         ones.push_back(to_push);
//     }
// }

// std::vector<double> PageRank::multiply(std::vector<std::vector<double>> A, std::vector<double> x) {
//     std::vector<double> to_return;
//     for (unsigned i = 0; i < A.size(); i++) {
//         double sum = 0;
//         for (unsigned j = 0; j < A.at(i).size(); j++) {
//             sum += A.at(i).at(j) * x.at(j);
//         }
//         to_return.push_back(sum);
//     }
//     return to_return;
// }
// std::vector<double> PageRank::power_iteration(double alpha, double tol, int max_iter) {

// }
// double PageRank::norm(std::vector<double> a, std::vector<double> a0) {
//     if (a.empty() || a0.empty() || a.size() != a0.size()) {
//         return -1;
//     }
//     std::vector<double> diff;
//     for (unsigned i = 0; i < a.size(); i++) {
//         diff.push_back((a.at(i) - a0.at(i)) * (a.at(i) - a0.at(i)));
//     }
//     double norm = std::accumulate(diff.begin(), diff.end(), 0);
//     return sqrt(norm);
// }