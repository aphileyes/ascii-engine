//
// Created by Aphile on 17.07.2025.
//

#ifndef LOGGER_H
#define LOGGER_H

namespace Logger {

    struct ILogger {
        virtual ~ILogger() = default;
        virtual void Write() = 0;
        virtual void WriteLine() = 0;

    protected:
        ILogger() = default;
    };

    class Logger final : public ILogger {
    public:
        Logger();

        void Write() override;
        void WriteLine() override;
    };

}  // namespace Logger

#endif  // LOGGER_H
