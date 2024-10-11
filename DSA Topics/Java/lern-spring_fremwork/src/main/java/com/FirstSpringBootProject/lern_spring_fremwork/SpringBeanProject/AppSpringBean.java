package com.FirstSpringBootProject.lern_spring_fremwork.SpringBeanProject;

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
		
		// Calling Bean by using Bean class name --
		System.out.println(Context.getBean(Address.class));
		
		
		//Calling person using method call 
		System.out.println(Context.getBean("person2MethodCall"));
		
		//Calling person using parameter
		System.out.println(Context.getBean("person3Parameter"));
		
		
		Context.close();
		
		

	}

}
