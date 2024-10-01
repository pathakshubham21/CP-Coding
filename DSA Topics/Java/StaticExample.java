class Mobile
{
    String Name;
    String Brand;
    static String Type;

    static 
    {
        Type = "Phone";
    }

    public Mobile()
    {s
        Name = "MyPhone";
        Brand  = "Nokia";
    }

    public void Display()
    {
        System.out.println("Name: "+Name+ " Brand: "+ Brand+ " Type: "+Type);
    }
}

class StaticExample
{
    public static void main(String arg[])
    {
        Mobile obj1 = new Mobile();
        obj1.Display();

        obj1.Name = "Iphone";
        obj1.Brand = "Apple";
        obj1.Type = "SmartPhone";
         obj1.Display();
    }
}




