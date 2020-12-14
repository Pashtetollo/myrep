package ua.lviv.iot.GreenHouseAPI.services;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import ua.lviv.iot.GreenHouseAPI.models.SensorType;
import ua.lviv.iot.GreenHouseAPI.repositories.SensorTypeRepository;
import java.util.List;

@Service
    public class SensorTypeService{
        @Autowired
    SensorTypeRepository sensorTypeRepository;
    public List<SensorType> getAllSensorTypes() {
        return sensorTypeRepository.findAll();
    }
    public SensorType getSensorTypeById(int id) {
        if (sensorTypeRepository.findById(id).isPresent()) {
            return sensorTypeRepository.findById(id).get();
        } else {
            return new SensorType(9999, "SensorType");
        }
    }
    public void addSensorType(SensorType newSensorType) {
        sensorTypeRepository.save(newSensorType);
    }

    public void deleteALLSensorTypes() {
        sensorTypeRepository.deleteAll();
    }

    public void deleteSensorTypeById(int id) {
        sensorTypeRepository.deleteById(id);
    }

}