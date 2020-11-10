package ua.lviv.iot.GreenHouseAPI.repositories;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;
import ua.lviv.iot.GreenHouseAPI.models.Data;

@Repository
public interface DataRepository extends JpaRepository<Data, Integer> {
}
