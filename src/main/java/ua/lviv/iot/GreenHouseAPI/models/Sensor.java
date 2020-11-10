package ua.lviv.iot.GreenHouseAPI.models;

import javax.persistence.*;

@Entity
@Table(name = "sensor")
public class Sensor {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Column(name = "id")
    private int id;

    @Column(name = "Uid")
    private int Uid;

    @Column(name = "sensor_type_id")
    private int sensorTypeId;

    public Sensor() {
    }

    public Sensor(int uid, int sensorTypeId) {
        Uid = uid;
        this.sensorTypeId = sensorTypeId;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getUid() {
        return Uid;
    }

    public void setUid(int uid) {
        Uid = uid;
    }

    public int getSensorTypeId() {
        return sensorTypeId;
    }

    public void setSensorTypeId(int sensorTypeId) {
        this.sensorTypeId = sensorTypeId;
    }

    @Override
    public String toString() {
        return "Sensor{" +
                "id=" + id +
                ", Uid=" + Uid +
                ", sensorTypeId=" + sensorTypeId +
                '}';
    }
}
