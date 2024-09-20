int x=5;
switch(x){
    case 5:
    System.out.println("five");
    case 4:
    System.out.println("six);
    default:
    System.out.println("default");
}

// New switch case 

switch (month) { 
    case JANUARY, JUNE, JULY -> 3; 
    case FEBRUARY, SEPTEMBER -> 1;
}

// Using yield
int x = switch (dayOfWeek) {
    case MONDAY:
        yield 2;
    case TUESDAY:
        yield 3;
    case WEDNESDAY:
        yield 4;
    default:
        yield 0;
};