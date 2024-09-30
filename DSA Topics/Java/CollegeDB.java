import java.util.*;

class StudentInfo {
    String Name;
    int RegNo;
    String Branch;
    int PassoutYear;
    static boolean IsLoggedIn = false;
    static int Login_fail_count = 0;


    public boolean Is_maximum_login_failed()
    {
        if(Login_fail_count>=3)
        {
            System.out.println("Maximum login faild time reached..");
            System.out.println("Try Again after sometime");
            System.out.println("Thanks...");
            Login_fail_count = 0;
            return true;
        }
        else
        {
            return false;
        }
    }

// Validating if user cradentials is correct
    public boolean Validatelogin(String Username, String Password) {
        if(Username.equals("admin") && Password.equals("password"))
        {
            return true;
        }
        else{
            System.out.println("Credentials are not correct.");
            System.out.println("Try again.");
            return false;
        }
        
    }
// Taking cradentials details from user 
    public boolean InputLogin() {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the username: ");
        String Username = sc.next();

        System.out.print("Enter the password: ");
        String Password = sc.next();

        if (Validatelogin(Username, Password)) {
            System.out.println("Logged in successfully."+"\n");
            IsLoggedIn = true;
            return true;
        } else {
            if(Is_maximum_login_failed())
            {
             return false;
            }
            Login_fail_count ++;
            InputLogin();
            return false;
        }
    }
    public void SignOut()
    {
        IsLoggedIn = false;
        return; 
    }
// Displaying Student Information 
    public void DisplayStudentData() {
            System.out.println("Student Name: " + Name +"\n"+ 
                               " Registration Number: " + RegNo +"\n"+  
                               " Branch: " + Branch + "\n"+ 
                               " Passout Year: " + PassoutYear+ "\n");
        
    }
// Adding New Student Information
    StudentInfo(String StudentName, int StudentRegNo, String StudentBranch, int StudentPassoutYear) {
        Name = StudentName;
        RegNo = StudentRegNo;
        Branch = StudentBranch;
        PassoutYear = StudentPassoutYear;
    }

    public void update()
    {
        if(IsLoggedIn)
        {
           while(true)
           {
                System.out.println("Select Data to Update");
                System.out.println("1. Name");
                System.out.println("2. Registration Number");
                System.out.println("3. Branch");
                System.out.println("4. Passout Year");
                System.out.println("5. Go to Main Menu");

                Scanner sc = new Scanner(System.in);
                int option = sc.nextInt();
                switch(option)
                {
                    case 1:
                        System.out.println("Enter new Name: ");
                        String NewName = sc.next();
                        Name = NewName;
                        System.out.println("Updated");
                        break;
                    case 2:
                        System.out.println("Can't update Registration Number");
                        System.out.println("Try other option");
                        break;

                    case 3:
                        System.out.println("Enter new Branch Name: ");
                        String NewBranch = sc.next();
                        Branch = NewBranch;
                        System.out.println("Updated");
                        break;

                    case 4:
                        System.out.println("Enter new Passout Year: ");
                        int NewPassoutYear = sc.nextInt();
                        PassoutYear = NewPassoutYear;
                        System.out.println("Updated");
                        break;

                    case 5:
                        System.out.println("Do you want to SignOut (Yes/No)?");
                        while(true)
                        {
                            String AskSignOut = sc.next();

                            if(AskSignOut.equals("Yes"))
                            {
                                SignOut();
                                return;
                            }
                            else if(AskSignOut.equals("No"))
                            {
                                return;
                            }
                            else{
                                System.out.println("Invalid Option");
                            }
                        }

                    default:
                        System.out.println("Invalid Option..");
                        System.out.println("Try Again..");

                }
           }

        }
        else{
            System.out.println("Login to update the Data");
            InputLogin();
            update();
        }
    } 


}

class CollegeDB { // Corrected class name
    public static void main(String[] args) {
        StudentInfo Student1 = new StudentInfo("Shubham", 1170, "CSE", 2021);
        StudentInfo Student2 = new StudentInfo("Robin", 1234, "ECE", 2022);
        Scanner sc = new Scanner(System.in);

        while(true)
        {
        System.out.println("Select Option");
        System.out.println("1. Display Student Data");
        System.out.println("2. Update Student Data");
        System.out.println("3. Exit");
        int Menu_Option_Main = sc.nextInt(); 
            switch(Menu_Option_Main)
                {
                    case 1:
                        Student1.DisplayStudentData();
                        break;
                    case 2:
                        Student1.update();
                        break;
                    case 3:
                        return;
                    default:
                        System.out.println("Invalid Option..");
                        System.out.println("Try Again..");
                }
        }

    }
}
