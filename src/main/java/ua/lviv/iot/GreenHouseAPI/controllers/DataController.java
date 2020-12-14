package ua.lviv.iot.GreenHouseAPI.controllers;
import ua.lviv.iot.GreenHouseAPI.services.DataService;
import net.minidev.json.JSONObject;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import ua.lviv.iot.GreenHouseAPI.models.Data;

import java.util.HashMap;
import java.util.List;

@RestController
@RequestMapping("/data")
public class DataController {

    @Autowired
    DataService dataService;

    private HashMap<String, String> responseMap;

    @GetMapping
    public ResponseEntity<List<Data>> getAllData() {
        return new ResponseEntity<>(dataService.getAllData(), HttpStatus.OK);
    }

    @GetMapping("/{id}")
    public ResponseEntity<Data> getDataById(@PathVariable int id) {
        return new ResponseEntity<>(dataService.getDataById(id), HttpStatus.OK);
    }

    @PostMapping
    public ResponseEntity<JSONObject> addNewData(@RequestBody Data data) {
        dataService.addData(data);
        responseMap = new HashMap<>();
        responseMap.put("message", "Successfully created");
        return new ResponseEntity<>(new JSONObject(responseMap), HttpStatus.CREATED);
    }

    @DeleteMapping
    public ResponseEntity<JSONObject> deleteAllData() {
        responseMap = new HashMap<>();
        responseMap.put("message", "Successfully deleted all objects");
        dataService.deleteALLData();
        return new ResponseEntity<>(new JSONObject(responseMap), HttpStatus.OK);
    }

    @DeleteMapping("/{id}")
    public ResponseEntity<JSONObject> deleteAllData(@PathVariable int id) {
        responseMap = new HashMap<>();
        responseMap.put("message", "Successfully deleted");
        dataService.deleteDataById(id);
        return new ResponseEntity<>(new JSONObject(responseMap), HttpStatus.OK);
    }
}
