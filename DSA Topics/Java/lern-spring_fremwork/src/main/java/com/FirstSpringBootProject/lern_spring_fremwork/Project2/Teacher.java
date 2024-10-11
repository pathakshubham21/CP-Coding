package com.FirstSpringBootProject.lern_spring_fremwork.Project2;

import org.springframework.context.annotation.Bean;
import org.springframework.stereotype.Component;


@Component
//record TeacherData(String name, int Salary)
//{}
public class Teacher {

//	public TeacherData teacher()
//	{
//		return new TeacherData("Shubham",10000);
//	}
	
	@Bean (name = "TeacherName")
	public String name()
	{
		return "Pathak";
	}
}
