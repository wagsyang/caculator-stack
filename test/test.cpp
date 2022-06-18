#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "expression.h"

TEST_CASE( "Expression Function Test", "Function" ) {
    
    Expression exp;
    SECTION("Expression::expresionValidation"){
        CHECK( exp.expresionValidation("1+2") == true );
        CHECK( exp.expresionValidation("1-2") == true );
        CHECK( exp.expresionValidation("1*2") == true );
        CHECK( exp.expresionValidation("1/2") == true );

        CHECK( exp.expresionValidation("1+2-3*12/1") == true );
        CHECK( exp.expresionValidation("1+2-3*12/0") == false );

        CHECK( exp.expresionValidation("1+1-") == false );
        CHECK( exp.expresionValidation("*1-1") == false );
        CHECK( exp.expresionValidation("1 2") == false );
        CHECK( exp.expresionValidation("1*2 ") == false );
        CHECK( exp.expresionValidation(" 1*2") == false );

        CHECK( exp.expresionValidation("1^2") == false );
        CHECK( exp.expresionValidation("1|2") == false );
        CHECK( exp.expresionValidation("1.2") == false );
        CHECK( exp.expresionValidation("1w2") == false );
        CHECK( exp.expresionValidation("1=2") == false );
        CHECK( exp.expresionValidation("1%2") == false );
        CHECK( exp.expresionValidation("1_2") == false );

        CHECK( exp.expresionValidation("a") == false );
        CHECK( exp.expresionValidation("abc") == false );
        CHECK( exp.expresionValidation("12abc") == false );
        CHECK( exp.expresionValidation("1+a") == false );

        // "()" not surpoted yet
        CHECK( exp.expresionValidation("(1-2)") == false );
        CHECK( exp.expresionValidation("(1-2") == false );
    }

    SECTION("Expression::caculateExpressionResult"){
        CHECK( exp.expresionValidation("1+2") );
        exp.caculateExpressionResult();
        CHECK( exp.getExpressionResult() == 3 );

        CHECK( exp.expresionValidation("1-2") );
        exp.caculateExpressionResult();
        CHECK( exp.getExpressionResult() == -1 );

        CHECK( exp.expresionValidation("1*2") );
        exp.caculateExpressionResult();
        CHECK( exp.getExpressionResult() == 2 );

        CHECK( exp.expresionValidation("2/2") );
        exp.caculateExpressionResult();
        CHECK( exp.getExpressionResult() == 1 );

        CHECK( exp.expresionValidation("10+2-1*12/2") );
        exp.caculateExpressionResult();
        CHECK( exp.getExpressionResult() == 6 );
    }
}
