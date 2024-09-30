class Mobile
{
    String name;
    int price;
    String brand;
    static String Network;

    public void Display()
    {
         System.out.println("Name: "+name + " Price: "+price + " Brand: "+brand+ " Network: "+Network);
    }
}

class StaticVariableExample
{
    public static void main (String arg[])
    {
        
        Mobile obj1 = new Mobile();
        obj1.name = "SmartPhone";
        obj1.price = 12000;
        obj1.brand = "Apple";
        obj1.Network = "Airtel";

        Mobile obj2 = new Mobile();
        obj2.name = "SmartPhone";
        obj2.price = 20000;
        obj2.brand = "Samsung";

        obj1.Display();
        obj2.Display();
        

    }
}