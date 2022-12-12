#include <data.h>

class PageRank {
    public:
        PageRank(DataParsing data);
        
        
        std::vector<int> findTopTen();
        
        
    private:
        std::vector<std::vector<double>> A_;
        std::vector<double> x_;
        std::vector<std::vector<double>> ones;
        std::vector<double> multiply(std::vector<std::vector<double>> A, std::vector<double> x);
        std::vector<double> power_iteration(double tol, int max_iter);
        double norm(std::vector<double> a, int nth);
        std::map<int, unsigned> mapping;

};