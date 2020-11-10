package ua.lviv.iot.GreenHouseAPI.services;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import ua.lviv.iot.GreenHouseAPI.models.Data;
import ua.lviv.iot.GreenHouseAPI.repositories.DataRepository;

import java.sql.Timestamp;
import java.util.Calendar;
import java.util.List;

@Service
public class DataService {

    @Autowired
    DataRepository dataRepository;

    public List<Data> getAllData() {
        return dataRepository.findAll();
    }

    public Data getDataById(int id) {
        if (dataRepository.findById(id).isPresent()) {
            return dataRepository.findById(id).get();
        } else {
            return new Data(9999, 9999, new Timestamp(Calendar.getInstance().getTime().getTime()));
        }
    }

    public void addData(Data newData) {
        dataRepository.save(newData);
    }

    public void deleteALLData() {
        dataRepository.deleteAll();
    }

    public void deleteDataById(int id) {
        dataRepository.deleteById(id);
    }
}
