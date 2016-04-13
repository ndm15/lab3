#include <eecs230.h>


// Created by Yang Hu on 4/13/16.
//

int main(){
    vector<double> parameters;
    cout << "enter the parameters a,b,c of the quadratic function\n";
    for(int i=0; i< 3; i++){
        double tmp;
        cin >> tmp;
        parameters.push_back(tmp);
    }
    double a = parameters[0];
    double b = parameters[1];
    double c = parameters[2];
    try{
        if((b*b - 4*a*c) > 0){
            vector<double> results;
            results.push_back((-b + sqrt(b*b - 4*a*c))/(2*a));
            results.push_back((-b - sqrt(b*b - 4*a*c))/(2*a));
            for(int i = 0; i < results.size(); i++){
                cout << "results[" << i <<"] is: " << results[i] << endl;
            }
        }else if((b*b - 4*a*c) == 0){
            double res = -b /(a*2);
            cout << "result is : " << res << endl;
        }else {
            throw 7;
        }
    } catch(int e){
        error("error");
    }
    return 0;
}
