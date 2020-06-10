package by.bsu.matrix.exception;

/**
 * The class {@code DateException} indicates when the date is incorrect
 * application might want to catch.
 * Created on 07.03.2020.
 *
 * @author Pozdnyakov I.V.
 * @version 1.0
 */
public class DateException extends Exception {

    /**
     * Constructor with the detail message.
     *
     * @param message the detail message. The detail message is saved for
     *                later retrieval by the {@link #getMessage()} method.
     */
    public DateException(String message) {
        super(message);
    }

    /**
     * Constructor with the detail message and
     * cause.
     *
     * @param message the detail message (which is saved for later retrieval
     *                by the {@link #getMessage()} method).
     * @param cause   the cause (which is saved for later retrieval by the
     *                {@link #getCause()} method).
     */
    public DateException(String message, Throwable cause) {
        super(message, cause);
    }

    /**
     * Constructor with the specified cause and a detail
     * message
     *
     * @param cause the cause (which is saved for later retrieval by the
     *              {@link #getCause()} method).
     */
    public DateException(Throwable cause) {
        super(cause);
    }

    /**
     * Constructor with the specified detail message,
     * cause, suppression enabled or disabled, and writable stack
     * trace enabled or disabled.
     *
     * @param message            the detail message.
     * @param cause              the cause. (A {@code null} value is permitted,
     *                           and indicates that the cause is nonexistent or unknown.)
     * @param enableSuppression  whether or not suppression is enabled
     *                           or disabled
     * @param writableStackTrace whether or not the stack trace should
     *                           be writable
     * @since 1.7
     */
    public DateException(String message, Throwable cause, boolean enableSuppression, boolean writableStackTrace) {
        super(message, cause, enableSuppression, writableStackTrace);
    }
}