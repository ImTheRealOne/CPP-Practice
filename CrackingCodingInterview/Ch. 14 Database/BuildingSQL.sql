

/*
CREATE TABLE Complex (
    ComplexID INT AUTO_INCREMENT NOT NULL ,
    ComplexName VARCHAR(100),
    CONSTRAINT pk_ComplexID PRIMARY KEY (ComplexID)
);



CREATE TABLE Buildings (
    BuildingID INT AUTO_INCREMENT NOT NULL,
    ComplexID INT NOT NULL,
    BuildingName VARCHAR(100),
    Address VARCHAR(500),
    CONSTRAINT pk_BuildapttenantsingID PRIMARY KEY (BuildingID),
    CONSTRAINT pk_ComplexID FOREIGN KEY (ComplexID)
        REFERENCES Complex (ComplexID)
        ON UPDATE CASCADE ON DELETE RESTRICT
);
   
    
    
    
CREATE TABLE Apartments (
    AptID INT AUTO_INCREMENT NOT NULL,
    UnitNumber VARCHAR(10),
    BuildingID INT  NOT NULL ,
    CONSTRAINT pk_AptID PRIMARY KEY (AptID),
    CONSTRAINT pk_BuildingID FOREIGN KEY (BuildingID)
		REFERENCES Buildings(BuildingID)
        ON UPDATE cascade on delete restrict
);

 
CREATE table Tenants ( 
	TenantID int AUTO_INCREMENT NOT NULL,
    TenantName varchar(100),
    Constraint pk_TenantID PRIMARY KEY(TenantID)
);



    
CREATE Table AptTenants (
	TenantID INT NOT NULL,
    AptID INT NOT NULL,
    CONSTRAINT pk_TenantID FOREIGN KEY(TenantID) 
		REFERENCES Tenants(TenantID) 
        On UPdate CASCADE on delete restrict,
    CONSTRAINT pk_AptID FOREIGN KEY (AptID) 
		REFERENCES Apartments (AptID)
        ON UPDATE CASCADE ON DELETE RESTRICT
);



Create Table Requests (
	RequestID INT AUTO_INCREMENT NOT NULL,
    ReqStatus ENUM	('OPEN', 'CLOSED', 'PENDING' ),
    AptID INT NOT NULL,
    Description varchar(500),
    CONSTRAINT pk_RequestID Primary Key(RequestID),
    Constraint pk_RequestAptID FOREIGN KEY (AptID)
		REFERENCES Apartments(AptID)
        On Update cascade on delete restrict
);

