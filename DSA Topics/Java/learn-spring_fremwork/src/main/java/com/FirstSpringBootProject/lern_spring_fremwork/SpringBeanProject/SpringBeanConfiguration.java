package com.FirstSpringBootProject.lern_spring_fremwork.SpringBeanProject;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Primary;

record Person(String name , int age, Address address) {};
record Address(String FirstLine, String City) {};

@Configuration
public class SpringBeanConfiguration {
	
	@Bean
	public String name()
	{
		return "Shubham";
	}
	@Bean 
	public int age()
	{
		return 22;
	}
	
	@Bean 
	public Person person()
	{
		return new Person("Shubham", 24, new Address("Civil Line", "Balrampur"));
	}
//	@Bean
//	public Address address()
//	{
//		return new Address("MG road", "Bangalore");
//	}
	
	@Bean(name = "address2")
	@Primary
	public Address address()
	{
		return new Address("MG road", "Bangalore");
	}
	
	@Bean(name = "address3")
	public Address address3()
	{
		return new Address("MG road", "Bangalore");
	}
	
	
	@Bean
	@Primary
	public Person person2MethodCall()
	{
		return new Person(name(), age(), address());
	}
	
	@Bean
	public Person person3Parameter(String name, int age, Address address2)
	{
		return new Person(name, age, new Address("Lal Kila", "Delhi"));
	}
	

}
