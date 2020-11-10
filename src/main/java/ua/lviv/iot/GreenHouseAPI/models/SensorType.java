package ua.lviv.iot.GreenHouseAPI.models;


import javax.persistence.*;

@Entity
@Table(name = "sensor_type")
public class SensorType {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Column(name = "id")
    private int id;

    @Column(name = "type")
    private String type;

    public SensorType() {
    }

    public SensorType(int id, String type) {
        this.id = id;
        this.type = type;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    @Override
    public String toString() {
        return "SensorTypeEntity{" +
                "id=" + id +
                ", type='" + type + '\'' +
                '}';
    }
}
