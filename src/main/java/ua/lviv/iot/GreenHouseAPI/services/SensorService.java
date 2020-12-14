package ua.lviv.iot.GreenHouseAPI.services;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import ua.lviv.iot.GreenHouseAPI.models.Data;
import ua.lviv.iot.GreenHouseAPI.models.Sensor;
import ua.lviv.iot.GreenHouseAPI.repositories.SensorRepository;

import java.sql.Timestamp;
import java.util.Calendar;
import java.util.List;
@Service
public class SensorService {

    @Autowired
    SensorRepository sensorRepository;

    public List<Sensor> getAllSensors() {
        return sensorRepository.findAll();
    }

    public Sensor getSensorById(int id) {
        if (sensorRepository.findById(id).isPresent()) {
            return sensorRepository.findById(id).get();
        } else {
            return new Sensor(9999, 9999);
        }
    }

    public void addSensor(Sensor newSensor) {
        sensorRepository.save(newSensor);
    }

    public void deleteALLSensors() {
        sensorRepository.deleteAll();
    }

    public void deleteSensorById(int id) {
        sensorRepository.deleteById(id);
    }
}



