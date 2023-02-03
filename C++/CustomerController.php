<?php
    require_once 'CustomerGateway.php';

    class CustomerController {
        private $db;
        private $requestMethod;
        private $customerId;
        private $customerGateway;
        private $tableName;


        public function __construct($db, $requestMethod, $customerId, $tableName)
        {
            $this->db = $db;
            $this->requestMethod = $requestMethod;
            $this->customerId = $customerId;
            $this->tableName = $tableName;
            $this->customerGateway = new CustomerGateway($db, $tableName);
        }

        public function processRequest()
        {
            $response = null;
            $method = $this->requestMethod;
            switch($method) {
                case 'GET':
                    if($this->customerId) {
                        $response = $this->getCustomer($this->customerId);
                    } else {
                        $response = $this->getAllCustomers();
                    }
                    break;
                case 'POST':
                    $response = $this->createCustomerFromRequest();
                    break;
                case 'PUT':
                    $response = $this->updateCustomerFromRequest($this->customerId);
                    break;
                case 'DELETE':
                    $response = $this->deleteCustomer($this->customerId);
                    break;
                default:
                    $response = $this->notFoundResponse();
                    break;
            }
            header($response['status_code_header']);
            if ($response['body']) {
                echo $response['body'];
            } else {
                $result = notFoundResponse();
                echo $result['body'];
            }
        }

        public function createTable()
        {
            $sql = "CREATE TABLE IF NOT EXISTS LICH_SU_TABLE_" . $this->tableName . " (
                MA_DON INT,
                SO_PHIEU INT,
                THU_TU INT,
                TEN_KHACH VARCHAR(255),
                DON_VI VARCHAR(255),
                DIA_DIEM VARCHAR(255),
                NGAY_TRON DATETIME,
                NHAN_VIEN_VAN_HANH VARCHAR(255),
                SO_XE VARCHAR(255),
                LAI_XE VARCHAR(255),
                DAT_HANG INT,
                TICH_LUY FLOAT,
                MAC_BE_TONG VARCHAR(255),
                M3_ME FLOAT,
                CHE_DO VARCHAR(255),
                CAT_1 FLOAT,
                DO_AM_CAT_1 FLOAT,
                CAT_2 FLOAT,
                DO_AM_CAT_2 FLOAT,
                DA_1 FLOAT,
                DO_AM_DA_1 FLOAT,
                DA_2 FLOAT,
                DO_AM_DA_2 FLOAT,
                DA_3 FLOAT,
                DO_AM_DA_3 FLOAT,
                XI_MANG_1 FLOAT,
                XI_MANG_2 FLOAT,
                XI_MANG_3 FLOAT,
                TRO_BAY FLOAT,
                NUOC FLOAT,
                PHU_GIA_1 FLOAT,
                PHU_GIA_2 FLOAT,
                TEN_PG1 VARCHAR(255),
                TEN_PG2 VARCHAR(255),
                GIO_BAT_DAU DATETIME,
                GIO_KET_THUC DATETIME,
                TINH_TRANG_DON BIT,
                CCAT_1 FLOAT,
                CCAT_2 FLOAT,
                CDA_1 FLOAT,
                CDA_2 FLOAT,
                CDA_3 FLOAT,
                CXI_MANG_1 FLOAT,
                CXI_MANG_2 FLOAT,
                CXI_MANG_3 FLOAT,
                CTRO_BAY FLOAT,
                CNUOC FLOAT,
                CPHU_GIA_1 FLOAT,
                CPHU_GIA_2 FLOAT,
                CCUONG_DO VARCHAR(255),
                CCOT_LIEU_MAX FLOAT,
                CDO_SUT VARCHAR(255),
                LOCKED BIT
            );
            ";
            try {
                $this->db.exec($sql); // create table
                $response['status_code_header'] = 'HTTP/1.1 200 OK';
                $response['body'] = json_encode(
                    ['result' => 'Success']
                );
                return $response;
            } catch(\PDOException $ex) {
                return unprocessableEntityResponse();
            }
            
        }

        public function getCustomer($customerId)
        {
            $result = $this->customerGateway->find($customerId);
            if(!$result) {
                return $this->notFoundResponse();
            }
            $response['status_code_header'] = 'HTTP/1.1 200 OK';
            $response['body'] = json_encode(
                ['result' => $result]
            );
            return $response;
        }

        public function getAllCustomers()
        {
            $result = $this->customerGateway->findAll();
            $response['status_code_header'] = 'HTTP/1.1 200 OK';
            $response['body'] = json_encode(
                ['result' => $result]
            );
            return $response;
        }

        public function createCustomerFromRequest()
        {
            $json = file_get_contents('php://input', TRUE);
            // var_dump($json); // show raw data in a variable
            $input = (array) json_decode($json);
            if(!$this->validateCustomer($input)) {
                return $this->unprocessableEntityResponse();
            }
            $result = $this->customerGateway->insert($input);
            $response['status_code_header'] = 'HTTP/1.1 201 Created';
            $response['body'] = json_encode(
                ['result' => $result]
            );
            return $response;
        }

        public function updateCustomerFromRequest($customerId)
        {
            $result = $this->customerGateway->find($customerId);
            if(!$result) {
                return $this->notFoundResponse();
            }
            $input = (array) json_decode(file_get_contents('php://input'), TRUE);
            if(!$this->validateCustomer($input)) {
                return $this->unprocessableEntityResponse();
            }
            $row = $this->customerGateway->update($customerId, $input);
            $response['status_code_header'] = 'HTTP/1.1 200 OK';
            $response['body'] = json_encode(
                ['result' => $row]
            );
            return $response;
        }

        public function deleteCustomer($customerId)
        {
            $result = $this->customerGateway->find(($customerId));
            if(!$result) {
                return $this->notFoundResponse();
            }
            $row = $this->customerGateway->delete($customerId);
            $response['status_code_header'] = 'HTTP/1.1 200 OK';
            $response['body'] = json_encode(
                ['result' => $row]
            );
            return $response;
        }

        public function notFoundResponse()
        {
            $response['status_code_header'] = 'HTTP/1.1 404 Not Found';
            $response['body'] = json_encode([
                'result' => null
            ]);
            return $response;
        }

        public function validateCustomer($input)
        {
            if(!isset($input['full_name'])) {
                return false;
            }
            return true;
        }

        public function unprocessableEntityResponse()
        {
            $response['status_code_header'] = 'HTTP/1.1 422 Unprocessable Entity';
            $response['body'] = json_encode([
                'result' => null
            ]);
            return $response;
        }
        
    }
