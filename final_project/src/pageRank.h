#include <data.h>

class PageRank {
    public:
        PageRank(DataParsing data);
        std::vector<double> multiply(std::vector<std::vector<double>> A, std::vector<double> x);
        std::vector<double> power_iteration(double alpha, double tol, int max_iter);
        double norm(std::vector<std::vector<double>> a, std::vector<std::vector<double>> a0);
    private:
        std::vector<std::vector<double>> A_;
        std::vector<double> b_;
        std::vector<double> x_;
        std::vector<std::vector<double>> ones;

};