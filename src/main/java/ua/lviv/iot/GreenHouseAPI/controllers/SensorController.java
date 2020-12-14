package ua.lviv.iot.GreenHouseAPI.controllers;

import net.minidev.json.JSONObject;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import ua.lviv.iot.GreenHouseAPI.models.Sensor;
import ua.lviv.iot.GreenHouseAPI.services.SensorService;

import java.util.HashMap;
import java.util.List;

@RestController
@RequestMapping("/sensor")
public class SensorController {
    @Autowired
    SensorService sensorService;
    private HashMap<String, String> responseMap;
    @GetMapping
    public ResponseEntity<List<Sensor>> getAllSensors() {
        return new ResponseEntity<>(sensorService.getAllSensors(), HttpStatus.OK);
    }
    @GetMapping("/{id}")
    public ResponseEntity<Sensor> getSensorById(@PathVariable int id) {
        return new ResponseEntity<>(sensorService.getSensorById(id), HttpStatus.OK);
    }
    @PostMapping
    public ResponseEntity<JSONObject> addNewSensor(@RequestBody Sensor sensor) {
        sensorService.addSensor(sensor);
        responseMap = new HashMap<>();
        responseMap.put("message", "Successfully created");
        return new ResponseEntity<>(new JSONObject(responseMap), HttpStatus.CREATED);
    }
    @DeleteMapping
    public ResponseEntity<JSONObject> deleteAllSensors() {
        responseMap = new HashMap<>();
        responseMap.put("message", "Successfully deleted all objects");
        sensorService.deleteALLSensors();
        return new ResponseEntity<>(new JSONObject(responseMap), HttpStatus.OK);
    }
    @DeleteMapping("/{id}")
    public ResponseEntity<JSONObject> deleteSensor(@PathVariable int id) {
        responseMap = new HashMap<>();
        responseMap.put("message", "Successfully deleted");
        sensorService.deleteSensorById(id);
        return new ResponseEntity<>(new JSONObject(responseMap), HttpStatus.OK);
    }
}
