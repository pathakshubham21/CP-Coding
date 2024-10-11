package com.FirstSpringBootProject.lern_spring_fremwork.SpringBeanProject;

import org.springframework.context.annotation.AnnotationConfigApplicationContext;

public class AppSpringBean {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		// Launch Spring Context
		var Context = new AnnotationConfigApplicationContext(SpringBeanConfiguration.class);
		
		// Get bean from Spring Context
		System.out.println(Context.getBean("name"));

	}

}
