package by.bsu.GoogleSpreadsheets.controller;

import com.google.api.client.auth.oauth2.Credential;
import com.google.api.client.extensions.java6.auth.oauth2.AuthorizationCodeInstalledApp;
import com.google.api.client.extensions.jetty.auth.oauth2.LocalServerReceiver;
import com.google.api.client.googleapis.auth.oauth2.GoogleAuthorizationCodeFlow;
import com.google.api.client.googleapis.auth.oauth2.GoogleClientSecrets;
import com.google.api.client.googleapis.javanet.GoogleNetHttpTransport;
import com.google.api.client.json.JsonFactory;
import com.google.api.client.json.jackson2.JacksonFactory;
import com.google.api.client.util.store.FileDataStoreFactory;
import com.google.api.services.sheets.v4.Sheets;
import com.google.api.services.sheets.v4.SheetsScopes;
import com.google.api.services.sheets.v4.model.Sheet;
import com.google.api.services.sheets.v4.model.UpdateValuesResponse;
import com.google.api.services.sheets.v4.model.ValueRange;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.security.GeneralSecurityException;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

public class SheetManipulator {
    private String applicationName;
    private JsonFactory jsonFactory;
    private String tokenDirectoryPath;
    private List<String> scopes;
    private String credentialsFilePath;
    private String spreadsheetId;

    public SheetManipulator(String token_directory_path, String credentials_file_path) {   // tokens and "/credentials.json"
        this.tokenDirectoryPath = token_directory_path;
        this.credentialsFilePath = credentials_file_path;
        applicationName = "Google Sheets API Java Quickstart";
        jsonFactory = JacksonFactory.getDefaultInstance();
        scopes = Collections.singletonList(SheetsScopes.SPREADSHEETS);
    }

    public SheetManipulator(String name, String token_directory_path, String credentials_file_path) {
        this(token_directory_path, credentials_file_path);
        this.applicationName = name;
    }

    private Credential getCredentials() throws IOException, GeneralSecurityException {
        // Load client secrets.
        InputStream in = SheetManipulator.class.getResourceAsStream(credentialsFilePath);
        if (in == null) {
            throw new FileNotFoundException("Resource not found: " + credentialsFilePath);
        }
        GoogleClientSecrets clientSecrets = GoogleClientSecrets.load(jsonFactory, new InputStreamReader(in));

        // Build flow and trigger user authorization request.
        GoogleAuthorizationCodeFlow flow = new GoogleAuthorizationCodeFlow.Builder(
                GoogleNetHttpTransport.newTrustedTransport(), jsonFactory, clientSecrets, scopes)
                .setDataStoreFactory(new FileDataStoreFactory(new java.io.File(tokenDirectoryPath)))
                .setAccessType("offline")
                .build();
        LocalServerReceiver receiver = new LocalServerReceiver.Builder().setPort(8888).build();
        return new AuthorizationCodeInstalledApp(flow, receiver).authorize("user");
    }

    private Sheets getService() throws GeneralSecurityException, IOException {
        return new Sheets.Builder(GoogleNetHttpTransport.newTrustedTransport(), jsonFactory, getCredentials())
                .setApplicationName(applicationName)
                .build();
    }

    public String showTable() throws IOException, GeneralSecurityException { //1NikstCejlPwT-iM3jCJIaeNeCZZVcVTLiY6U1ux0ISg
        Sheets service = getService();
        String range = "Class Data!A1:D";

        ValueRange response = service.spreadsheets().values()
                .get(spreadsheetId, range)
                .execute();
        StringBuilder stringBuilder = new StringBuilder();
        for (List<Object> line : response.getValues()) {
            for (Object item : line) {
                stringBuilder.append((String) item).append(", ");
            }
            stringBuilder.append("\n");
        }
        return stringBuilder.toString();
    }

    public String addLine(String name, String surname, String thirdName, int age) throws IOException, GeneralSecurityException { //1NikstCejlPwT-iM3jCJIaeNeCZZVcVTLiY6U1ux0ISg
        Sheets service = getService();
        String range = "Class Data!A1:D";
        ValueRange response = service.spreadsheets().values()
                .get(spreadsheetId, range)
                .execute();
        StringBuilder stringBuilder = new StringBuilder();
        String line = "A" + String.valueOf(response.getValues().size() + 1);
        ValueRange body = new ValueRange().setValues(Arrays.asList(Arrays.asList(name, surname, thirdName, age)));
        service.spreadsheets().values()
                .update(spreadsheetId, line, body)
                .setValueInputOption("RAW").execute();
        return stringBuilder.toString();
    }


    public String getSpreadsheetId() {
        return spreadsheetId;
    }

    public void setSpreadsheetId(String spreadsheetId) {
        this.spreadsheetId = spreadsheetId;
    }
}