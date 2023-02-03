<?php
    require_once 'connection.php';
    require_once 'CustomerController.php';
    // use CustomerController;

    header("Access-Control-Allow-Origin: *");
    header("Content-Type: application/json; charset=UTF-8");
    header("Access-Control-Allow-Methods: OPTIONS,GET,POST,PUT,DELETE");
    header("Access-Control-Max-Age: 3600");
    header("Access-Control-Allow-Headers: Content-Type, Access-Control-Allow-Headers, Authorization, X-Requested-With");

    $uri = parse_url($_SERVER['REQUEST_URI'], PHP_URL_PATH);
    $url = 'https://' . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI']; // get current url from server
    $url_components = parse_url($url); // split component of url
    $uri = explode('/', $uri);
    parse_str($url_components['query'], $params); // create array of components

    // all entry start with customer
    if($uri[3] !== 'customer') {
        header("HTTP/1.1 404 Not Found");
        exit();
    }

    $customerId = null;
    if(isset($uri[4])) {
        $customerId = (int)$uri[4];
    }
    $tableName = $params['tbl'];
    $action = $params['action'];
    $requestMethod = $_SERVER["REQUEST_METHOD"];
    
    //echo 'Table Name: ' . $tableName;
    // pass the request method and customer id to controller to process and response
    $controller = new CustomerController($conn, $requestMethod, $customerId, $tableName);
    if($action == 'create_table') {
        $controller->createTable();
    } else {
        $controller->processRequest();
    }
?>