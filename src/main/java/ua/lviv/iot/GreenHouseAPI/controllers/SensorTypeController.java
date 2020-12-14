package ua.lviv.iot.GreenHouseAPI.controllers;

import net.minidev.json.JSONObject;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import ua.lviv.iot.GreenHouseAPI.models.Data;
import ua.lviv.iot.GreenHouseAPI.models.SensorType;
import ua.lviv.iot.GreenHouseAPI.services.SensorTypeService;

import java.util.HashMap;
import java.util.List;

@RestController
@RequestMapping("/sensorType")
public class SensorTypeController {
    @Autowired

    SensorTypeService sensorTypeService;
    private HashMap<String, String> responseMap;

    @GetMapping
    public ResponseEntity<List<SensorType>> getAllData() {
        return new ResponseEntity<>(sensorTypeService.getAllSensorTypes(), HttpStatus.OK);
    }

    @GetMapping("/{id}")
    public ResponseEntity<SensorType> getSensorTypeById(@PathVariable int id) {
        return new ResponseEntity<>(sensorTypeService.getSensorTypeById(id), HttpStatus.OK);
    }

    @PostMapping
    public ResponseEntity<JSONObject> addNewSensorType(@RequestBody SensorType sensorType) {
        sensorTypeService.addSensorType(sensorType);
        responseMap = new HashMap<>();
        responseMap.put("message", "Successfully created");
        return new ResponseEntity<>(new JSONObject(responseMap), HttpStatus.CREATED);
    }
    @DeleteMapping
    public ResponseEntity<JSONObject> deleteAllSensorTypes() {
        responseMap = new HashMap<>();
        responseMap.put("message", "Successfully deleted all objects");
        sensorTypeService.deleteALLSensorTypes();
        return new ResponseEntity<>(new JSONObject(responseMap), HttpStatus.OK);
    }

    @DeleteMapping("/{id}")
    public ResponseEntity<JSONObject> deleteAllSensorTypes(@PathVariable int id) {
        responseMap = new HashMap<>();
        responseMap.put("message", "Successfully deleted");
        sensorTypeService.deleteSensorTypeById(id);
        return new ResponseEntity<>(new JSONObject(responseMap), HttpStatus.OK);
    }
}
