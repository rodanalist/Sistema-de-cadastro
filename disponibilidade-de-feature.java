public class LoginController { private final FeatureSet features; public LoginController(FeatureSet features) { this.features = features; }

public Usuario login(Map parametros) { LoginFeature login = features.for(Login.class); return login.valida(...); } } 