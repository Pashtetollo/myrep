package ua.lviv.iot.GreenHouseAPI.controllers;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import ua.lviv.iot.GreenHouseAPI.models.Data;
import ua.lviv.iot.GreenHouseAPI.services.DataService;

import java.util.List;

@RestController
@RequestMapping("data")
public class DataController {

    @Autowired
    DataService dataService;

    @GetMapping
    public List<Data> getAllData() {
        return dataService.getAllData();
    }

    @GetMapping("/{id}")
    public Data getDataById(@PathVariable int id) {
        return dataService.getDataById(id);
    }

    @PostMapping
    public void addNewData(@RequestBody Data data) {
        dataService.addData(data);
    }

    @DeleteMapping
    public void deleteAllData() {
        dataService.deleteALLData();
    }

    @DeleteMapping("/{id}")
    public void deleteAllData(@PathVariable int id) {
        dataService.deleteDataById(id);
    }
}
