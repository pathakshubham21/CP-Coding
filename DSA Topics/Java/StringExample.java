class StringExample
{
    public static void main(String arg[])
    {
        String name = new String("Shubham");
        for(int i = 0;i<name.length(); i++)
        {
            System.out.print(name.charAt(i));
        }
        System.out.print("\n");
        int nums[] = new int[5];
        nums[0] = 10;
        nums[1] = 11;
        nums[2] = 12;
        nums[3] = 13;
        nums[4] = 14;

        for(int n: nums)
        {
            System.out.println(n);
        }

    }
}