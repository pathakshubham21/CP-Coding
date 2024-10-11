package com.FirstSpringBootProject.lern_spring_fremwork.SpringBeanProject;

import java.util.Arrays;

import org.springframework.context.annotation.AnnotationConfigApplicationContext;

public class AppSpringBean {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		// Launch Spring Context
		var Context = new AnnotationConfigApplicationContext(SpringBeanConfiguration.class);
		
		// Get bean from Spring Context
		System.out.println(Context.getBean("name"));
		System.out.println(Context.getBean("age"));
		
		System.out.println(Context.getBean("person"));
//		System.out.println(Context.getBean("address"));
		
		
		//  Calling Bean by using Bean custom name --
		System.out.println(Context.getBean("address2"));
		
		
		//Calling person using method call 
		System.out.println(Context.getBean("person2MethodCall"));
		
		//Calling person using parameter
		System.out.println(Context.getBean("person3Parameter"));
		
		
		// Printing all spring beans names
		Arrays.stream(Context.getBeanDefinitionNames())
		.forEach(System.out::println);
		
		// Calling Bean by using Bean class name and Primary Concept --
		System.out.println(Context.getBean(Address.class));
		
		// Calling Bean by using Bean class name and Primary Concept --
		System.out.println(Context.getBean(Person.class));
		
		
		Context.close();
		
		

	}

}
