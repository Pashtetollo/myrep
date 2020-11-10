package ua.lviv.iot.GreenHouseAPI.models;


import javax.persistence.*;
import java.sql.Timestamp;

@Entity
@Table(name = "data")
public class Data {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Column(name = "id")
    private int id;

    @Column(name = "sensor_id")
    private int sensorId;

    @Column(name = "data")
    private double value;

    @Column(name = "timestamp")
    private Timestamp timestamp;

    public Data() {
    }

    public Data(int sensorId, double value, Timestamp timestamp) {
        this.sensorId = sensorId;
        this.value = value;
        this.timestamp = timestamp;
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public int getSensorId() {
        return sensorId;
    }

    public void setSensorId(int sensorId) {
        this.sensorId = sensorId;
    }

    public double getValue() {
        return value;
    }

    public void setValue(double value) {
        this.value = value;
    }

    public Timestamp getTimestamp() {
        return timestamp;
    }

    public void setTimestamp(Timestamp timestamp) {
        this.timestamp = timestamp;
    }

    @Override
    public String toString() {
        return "Data{" +
                "id=" + id +
                ", sensorId=" + sensorId +
                ", value=" + value +
                ", timestamp=" + timestamp +
                '}';
    }
}
