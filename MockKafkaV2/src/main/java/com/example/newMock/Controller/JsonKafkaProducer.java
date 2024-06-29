package com.example.newMock.Controller;

import com.example.newMock.Model.User;
import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import com.example.newMock.Model.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.kafka.core.KafkaTemplate;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/mock/message")
@RequiredArgsConstructor
@Slf4j
public class JsonKafkaProducer {

    @Autowired
    private KafkaTemplate<Long, User> kafkaTemplate;

    @PostMapping(value = "/send/{topic}]",
            consumes = MediaType.APPLICATION_JSON_VALUE,
            produces = MediaType.APPLICATION_JSON_VALUE
    )
    public ResponseEntity<Object> sendMessage(@PathVariable String topic, @RequestBody User message) {
        try {
            kafkaTemplate.send(topic, message);
            log.info("Message sent to topic {}", topic);
        } catch (Exception e) {
            log.error(e.getMessage(), e);
            return ResponseEntity.status(HttpStatus.BAD_REQUEST).body(e.getMessage());
        }
        return ResponseEntity.status(HttpStatus.OK).body(message);
    }
}
/*import com.example.newMock.Model.User;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.kafka.core.KafkaTemplate;
import org.springframework.kafka.support.KafkaHeaders;
import org.springframework.messaging.Message;
import org.springframework.messaging.support.MessageBuilder;
import org.springframework.stereotype.Service;

@Service
public class JsonKafkaProducer{
    private Logger kafkLog = LoggerFactory.getLogger(JsonKafkaProducer.class);
    private KafkaTemplate<String, User> kafkaTemplate;

    public JsonKafkaProducer(KafkaTemplate<String, User> kafkaTemplate) {
        this.kafkaTemplate = kafkaTemplate;
    }



    public void sendMessage(User data){

        kafkLog.info(String.format("Message send -> %s", data.toString()));

        Message<User> message = MessageBuilder.withPayload(data).setHeader(KafkaHeaders.TOPIC, "group3_tests").build();

        kafkaTemplate.send(message);

    }
}*/