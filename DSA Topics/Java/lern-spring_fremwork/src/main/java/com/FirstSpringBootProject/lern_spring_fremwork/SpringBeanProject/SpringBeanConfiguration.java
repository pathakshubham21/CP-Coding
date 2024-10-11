package com.FirstSpringBootProject.lern_spring_fremwork.SpringBeanProject;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class SpringBeanConfiguration {
	
	@Bean
	public String name()
	{
		return "Shubham";
	}

}
