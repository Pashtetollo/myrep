-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS = @@UNIQUE_CHECKS, UNIQUE_CHECKS = 0;
SET @OLD_FOREIGN_KEY_CHECKS = @@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS = 0;
SET @OLD_SQL_MODE = @@SQL_MODE, SQL_MODE =
        'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema GreenHouseDB
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema GreenHouseDB
-- -----------------------------------------------------

DROP DATABASE IF EXISTS `GreenHouseDB`;

CREATE SCHEMA IF NOT EXISTS `GreenHouseDB` DEFAULT CHARACTER SET utf8;
USE `GreenHouseDB`;

-- -----------------------------------------------------
-- Table `GreenHouseDB`.`sensor`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `GreenHouseDB`.`sensor`
(
    `id`             INT NOT NULL AUTO_INCREMENT,
    `Uid`            INT NOT NULL,
    `sensor_type_id` INT NOT NULL,
    PRIMARY KEY (`id`),
    INDEX fk_sensor_sensor_type_idx (sensor_type_id ASC) VISIBLE,
    CONSTRAINT fk_sensor_sensor_type
        FOREIGN KEY (sensor_type_id)
            REFERENCES GreenHouseDB.sensor_type (id)
            ON DELETE NO ACTION
            ON UPDATE NO ACTION
)
    ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `GreenHouseDB`.`data`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `GreenHouseDB`.`data`
(
    `id`        INT      NOT NULL AUTO_INCREMENT,
    `sensor_id` INT      NOT NULL,
    `data`      FLOAT    NOT NULL,
    `timestamp` DATETIME NOT NULL,
    PRIMARY KEY (`id`),
    INDEX `fk_data_sensor_idx` (`sensor_id` ASC) VISIBLE,
    CONSTRAINT `fk_data_sensor`
        FOREIGN KEY (`sensor_id`)
            REFERENCES `GreenHouseDB`.`sensor` (`id`)
            ON DELETE NO ACTION
            ON UPDATE NO ACTION
)
    ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `GreenHouseDB`.`sensor_type`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `GreenHouseDB`.`sensor_type`
(
    `id`   INT NOT NULL AUTO_INCREMENT,
    `type` VARCHAR(20) NOT NULL,
    PRIMARY KEY (`id`)
)
    ENGINE = InnoDB;


SET SQL_MODE = @OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS = @OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS = @OLD_UNIQUE_CHECKS;

insert into sensor_type
values (1, 'Temp'),
       (2, 'Hum');
