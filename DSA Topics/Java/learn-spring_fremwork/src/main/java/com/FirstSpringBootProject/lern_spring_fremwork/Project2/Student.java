package com.FirstSpringBootProject.lern_spring_fremwork.Project2;

import org.springframework.context.annotation.Bean;
import org.springframework.stereotype.Component;


@Component
public class Student {

	// This is Co
	@Bean (name = "StudentName")
	public String name()
	{
		return "Shubham";
	}
}
