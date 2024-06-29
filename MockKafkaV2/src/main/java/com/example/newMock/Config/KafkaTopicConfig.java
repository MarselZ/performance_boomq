package com.example.newMock.Config;

import org.apache.kafka.clients.admin.NewTopic;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;


@Configuration
public class KafkaTopicConfig {

    @Bean
    public NewTopic kafkaTopic(){
        return new NewTopic("kafka-topic-group-3", 1, (short) 1);
    }
}
