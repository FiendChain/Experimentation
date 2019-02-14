package net.exception;

public class ValueError extends Exception {
    private static final long serialVersionUID = 69;

    public ValueError() { 
        super(); 
    }
    
    public ValueError(String msg) { 
        super(msg); 
    }

    public ValueError(Throwable cause) { 
        super(cause); 
    }
    
    public ValueError(String msg, Throwable cause, boolean isSuppressed, boolean showStackTrace) {
        super(msg, cause, isSuppressed, showStackTrace);
    }
}