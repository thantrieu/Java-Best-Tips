<?php
    class CustomerGateway {
        private $db = null;
        private $tableName = null;

        public function __construct($db, $tblName)
        {
            $this->db = $db;
            $this->tableName = $tblName;
        }

        public function findAll()
        {
            $sql = "select * from ".$this->tableName;
            try {
                $cmd = $this->db->query($sql);
                $result = $cmd->fetchAll(\PDO::FETCH_ASSOC);
                return $result;
            } catch(\PDOException $e) {
                exit($e->getMessage());
            }
        }

        public function find($id)
        {
            $sql = "select * from " . $this->tableName . " where id = ?";
            try {
                $statement = $this->db->prepare($sql);
                $statement->execute(array($id));
                $result = $statement->fetchAll(\PDO::FETCH_ASSOC);
                return $result;
            } catch(\PDOException $e) {
                exit($e->getMessage());
            }
        }

        public function insert(Array $input)
        {
            $sql = 'insert into ' . $this->tableName . '(full_name, address, phone_number)
            values(:full_name, :address, :phone_number);';
            try {
                $statement = $this->db->prepare($sql);
                $statement->execute(array(
                    'full_name' => $input['full_name'] ?? null,
                    'address' => $input['address'] ?? null,
                    'phone_number' => $input['phone_number'] ?? null
                ));
                return $statement->rowCount();
            } catch(\PDOException $e) {
                exit($e->getMessage());
            }
        }

        public function update($id, Array $input)
        {
            $sql = "
            update " . $this->tableName . " 
            set 
                full_name = :full_name,
                address = :address,
                phone_number = :phone_number 
            where 
                id = :id";
            try {
                $statement = $this->db->prepare($sql);
                $statement->execute(array(
                    'id' => (int)$id,
                    'full_name' => $input['full_name'] ?? null,
                    'address' => $input['address'] ?? null,
                    'phone_number' => $input['phone_number'] ?? null
                ));
                return $statement->rowCount();
            } catch(\PDOException $e) {
                exit($e->getMessage());
            }
        }

        public function delete($id)
        {
            $sql = "delete from " . $this->tableName . " where id = :id";
            try {
                $statement = $this->db->prepare($sql);
                $statement->execute(array('id' => $id));
                return $statement->rowCount();
            } catch(\PDOException $e) {
                exit($e->getMessage());
            }
        }
    }
?>