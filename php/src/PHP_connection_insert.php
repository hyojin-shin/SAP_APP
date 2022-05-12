<?php
$con = @new mysqli("ip", "id", "pass", "test");

if ($con->connect_errno) {
    echo "Connect Error: " . $con->connect_errno;
}

$mode = $_POST['mode'];

if ( $mode == "1"){  
  $zone = $_POST['zone'];
  $sql = "INSERT INTO APP_table(mode,zone,date) VALUES('$mode', '$zone', NOW())";
}
else{
  $sql = "INSERT INTO APP_table(mode,date) VALUES('$mode', NOW())";
}

$result = mysqli_query($con, $sql);

if($sql)
  if($mode == "1"){
    echo "add mode: $mode zone $zone";
  }
  else{
    echo "add mode: $mode";
  }
 else
  echo "failure";

mysqli_close($con)

?>