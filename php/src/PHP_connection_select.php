<?php
$con = @new mysqli("13.124.47.96", "IMP", "Sap1004!", "test");

if ($con->connect_errno) {
    echo "Connect Error: " . $con->connect_errno;
}

mysqli_set_charset($con,"utf8");

$res0 = mysqli_query($con,"select pmsdata from test_table where spot = 0 ORDER BY id DESC LIMIT 1");
$res1 = mysqli_query($con,"select pmsdata from test_table where spot = 1 ORDER BY id DESC LIMIT 1");
$res2 = mysqli_query($con,"select pmsdata from test_table where spot = 2 ORDER BY id DESC LIMIT 1");
$res3 = mysqli_query($con,"select pmsdata from test_table where spot = 3 ORDER BY id DESC LIMIT 1");

$result = array();

while($row = mysqli_fetch_array($res)){

  array_push($result,
    array('id'=>$row[0]
  ));
}

echo json_encode(array("result"=>$result));
mysqli_close($con);

?>