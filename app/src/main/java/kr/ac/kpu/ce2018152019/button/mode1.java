package kr.ac.kpu.ce2018152019.button;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import com.android.volley.AuthFailureError;
import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;

import java.util.HashMap;
import java.util.Map;

public class mode1 extends AppCompatActivity {

    static RequestQueue requestQueue;

    Button zone0;
    Button zone1;
    Button zone2;
    Button zone3;
    TextView mode1_result;
    private RequestQueue queue;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.mode1);
        setTitle("Select zone");

        zone0 = (Button) findViewById(R.id.zone0);
        zone1 = (Button) findViewById(R.id.zone1);
        zone2 = (Button) findViewById(R.id.zone2);
        zone3 = (Button) findViewById(R.id.zone3);
        mode1_result = (TextView) findViewById(R.id.mode1_result);

    }
    public void clickZone0(View v) {
        String URL = "http://10.0.2.2/PHP_connection_insert.php";
        StringRequest stringRequest = new StringRequest(Request.Method.POST, URL, new Response.Listener<String>() {
            @Override
            public void onResponse(String response) {
                mode1_result.setText(response);
            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
                mode1_result.setText(error.getMessage());
                Toast.makeText(mode1.this, "ERROR", Toast.LENGTH_LONG).show();
            }
        }) {
            //POST 방식으로 보낼 데이터를
            //리턴해주는 콜백 메소드

            @Override
            protected Map<String, String> getParams() throws AuthFailureError {

                HashMap<String, String> datas = new HashMap<>();
                datas.put("mode", "1");
                datas.put("zone", "0");

                return datas;
            }
        };

        RequestQueue requestQueue = Volley.newRequestQueue(this);
        requestQueue.add(stringRequest);
    }

    public void clickZone1(View v) {
        String URL = "http://10.0.2.2/PHP_connection_insert.php";
        StringRequest stringRequest = new StringRequest(Request.Method.POST, URL, new Response.Listener<String>() {
            @Override
            public void onResponse(String response) {
                mode1_result.setText(response);
            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
                mode1_result.setText(error.getMessage());
                Toast.makeText(mode1.this, "ERROR", Toast.LENGTH_LONG).show();
            }
        }) {
            //POST 방식으로 보낼 데이터를
            //리턴해주는 콜백 메소드

            @Override
            protected Map<String, String> getParams() throws AuthFailureError {

                HashMap<String, String> datas = new HashMap<>();
                datas.put("mode", "1");
                datas.put("zone", "1");

                return datas;
            }
        };

        RequestQueue requestQueue = Volley.newRequestQueue(this);
        requestQueue.add(stringRequest);
    }


    public void clickZone2(View v) {
        String URL = "http://10.0.2.2/PHP_connection_insert.php";
        StringRequest stringRequest = new StringRequest(Request.Method.POST, URL, new Response.Listener<String>() {
            @Override
            public void onResponse(String response) {
                mode1_result.setText(response);
            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
                mode1_result.setText(error.getMessage());
                Toast.makeText(mode1.this, "ERROR", Toast.LENGTH_LONG).show();
            }
        }) {
            //POST 방식으로 보낼 데이터를
            //리턴해주는 콜백 메소드

            @Override
            protected Map<String, String> getParams() throws AuthFailureError {

                HashMap<String, String> datas = new HashMap<>();
                datas.put("mode", "1");
                datas.put("zone", "2");

                return datas;
            }
        };

        RequestQueue requestQueue = Volley.newRequestQueue(this);
        requestQueue.add(stringRequest);
    }

    public void clickZone3(View v) {
        String URL = "http://10.0.2.2/PHP_connection_insert.php";
        StringRequest stringRequest = new StringRequest(Request.Method.POST, URL, new Response.Listener<String>() {
            @Override
            public void onResponse(String response) {
                mode1_result.setText(response);
            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
                mode1_result.setText(error.getMessage());
                Toast.makeText(mode1.this, "ERROR", Toast.LENGTH_LONG).show();
            }
        }) {
            //POST 방식으로 보낼 데이터를
            //리턴해주는 콜백 메소드

            @Override
            protected Map<String, String> getParams() throws AuthFailureError {

                HashMap<String, String> datas = new HashMap<>();
                datas.put("mode", "1");
                datas.put("zone", "3");

                return datas;
            }
        };

        RequestQueue requestQueue = Volley.newRequestQueue(this);
        requestQueue.add(stringRequest);
    }
}
