package com.FirstSpringBootProject.lern_spring_fremwork.Project2;

import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

@Configuration
@ComponentScan("com.FirstSpringBootProject.lern_spring_fremwork.Project2")

public class SpringBean_Application_Launcher {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		var Context = new AnnotationConfigApplicationContext(SpringBean_Application_Launcher.class);
		
		System.out.println(Context.getBean("TeacherName"));
		System.out.println(Context.getBean("StudentName"));
//		System.out.println(Context.getBean("salary"));

	}

}
