

class Calculator
{
    public int add(int n1, int n2)
    {
        int r = n1+n2;
        return r;
    }
}

public class Demo1
{
    public static void main(String arg[])
    {
        int num1 = 10;
        int num2 = 81;
        Calculator calc  = new Calculator();

        int result = calc.add(num1, num2);
        
        System.out.println("Addition of two number is: "+result);

    }
}