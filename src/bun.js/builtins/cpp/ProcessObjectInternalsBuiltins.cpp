/*
 * Copyright (c) 2015 Igalia
 * Copyright (c) 2015 Igalia S.L.
 * Copyright (c) 2015 Igalia.
 * Copyright (c) 2015, 2016 Canon Inc. All rights reserved.
 * Copyright (c) 2015, 2016, 2017 Canon Inc.
 * Copyright (c) 2016, 2020 Apple Inc. All rights reserved.
 * Copyright (c) 2022 Codeblog Corp. All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

// DO NOT EDIT THIS FILE. It is automatically generated from JavaScript files for
// builtins by the script: Source/JavaScriptCore/Scripts/generate-js-builtins.py

#include "config.h"
#include "ProcessObjectInternalsBuiltins.h"

#include "WebCoreJSClientData.h"
#include <JavaScriptCore/HeapInlines.h>
#include <JavaScriptCore/IdentifierInlines.h>
#include <JavaScriptCore/ImplementationVisibility.h>
#include <JavaScriptCore/Intrinsic.h>
#include <JavaScriptCore/JSCJSValueInlines.h>
#include <JavaScriptCore/JSCellInlines.h>
#include <JavaScriptCore/StructureInlines.h>
#include <JavaScriptCore/VM.h>

namespace WebCore {

const JSC::ConstructAbility s_processObjectInternalsGetStdioWriteStreamCodeConstructAbility = JSC::ConstructAbility::CannotConstruct;
const JSC::ConstructorKind s_processObjectInternalsGetStdioWriteStreamCodeConstructorKind = JSC::ConstructorKind::None;
const JSC::ImplementationVisibility s_processObjectInternalsGetStdioWriteStreamCodeImplementationVisibility = JSC::ImplementationVisibility::Public;
const int s_processObjectInternalsGetStdioWriteStreamCodeLength = 9767;
static const JSC::Intrinsic s_processObjectInternalsGetStdioWriteStreamCodeIntrinsic = JSC::NoIntrinsic;
const char* const s_processObjectInternalsGetStdioWriteStreamCode =
    "(function (fd_, rawRequire) {\n" \
    "  var module = { path: \"node:process\", require: rawRequire };\n" \
    "  var require = path => module.require(path);\n" \
    "\n" \
    "  function createStdioWriteStream(fd_) {\n" \
    "    var { Duplex, eos, destroy } = require(\"node:stream\");\n" \
    "    var StdioWriteStream = class StdioWriteStream extends Duplex {\n" \
    "      #writeStream;\n" \
    "      #readStream;\n" \
    "\n" \
    "      #readable = true;\n" \
    "      #writable = true;\n" \
    "      #fdPath;\n" \
    "\n" \
    "      #onClose;\n" \
    "      #onDrain;\n" \
    "      #onFinish;\n" \
    "      #onReadable;\n" \
    "      #isTTY;\n" \
    "\n" \
    "      get isTTY() {\n" \
    "        return (this.#isTTY ??= require(\"node:tty\").isatty(fd_));\n" \
    "      }\n" \
    "\n" \
    "      get fd() {\n" \
    "        return fd_;\n" \
    "      }\n" \
    "\n" \
    "      constructor(fd) {\n" \
    "        super({ readable: true, writable: true });\n" \
    "        this.#fdPath = `/dev/fd/${fd}`;\n" \
    "      }\n" \
    "\n" \
    "      #onFinished(err) {\n" \
    "        const cb = this.#onClose;\n" \
    "        this.#onClose = null;\n" \
    "\n" \
    "        if (cb) {\n" \
    "          cb(err);\n" \
    "        } else if (err) {\n" \
    "          this.destroy(err);\n" \
    "        } else if (!this.#readable && !this.#writable) {\n" \
    "          this.destroy();\n" \
    "        }\n" \
    "      }\n" \
    "\n" \
    "      _destroy(err, callback) {\n" \
    "        if (!err && this.#onClose !== null) {\n" \
    "          var AbortError = class AbortError extends Error {\n" \
    "            constructor(message = \"The operation was aborted\", options = void 0) {\n" \
    "              if (options !== void 0 && typeof options !== \"object\") {\n" \
    "                throw new Error(`Invalid AbortError options:\\n" \
    "\\n" \
    "${JSON.stringify(options, null, 2)}`);\n" \
    "              }\n" \
    "              super(message, options);\n" \
    "              this.code = \"ABORT_ERR\";\n" \
    "              this.name = \"AbortError\";\n" \
    "            }\n" \
    "          };\n" \
    "          err = new AbortError();\n" \
    "        }\n" \
    "\n" \
    "        this.#onDrain = null;\n" \
    "        this.#onFinish = null;\n" \
    "        if (this.#onClose === null) {\n" \
    "          callback(err);\n" \
    "        } else {\n" \
    "          this.#onClose = callback;\n" \
    "          if (this.#writeStream) destroy(this.#writeStream, err);\n" \
    "          if (this.#readStream) destroy(this.#readStream, err);\n" \
    "        }\n" \
    "      }\n" \
    "\n" \
    "      _write(chunk, encoding, callback) {\n" \
    "        if (!this.#writeStream) {\n" \
    "          var { createWriteStream } = require(\"node:fs\");\n" \
    "          var stream = (this.#writeStream = createWriteStream(this.#fdPath));\n" \
    "\n" \
    "          stream.on(\"finish\", () => {\n" \
    "            if (this.#onFinish) {\n" \
    "              const cb = this.#onFinish;\n" \
    "              this.#onFinish = null;\n" \
    "              cb();\n" \
    "            }\n" \
    "          });\n" \
    "\n" \
    "          stream.on(\"drain\", () => {\n" \
    "            if (this.#onDrain) {\n" \
    "              const cb = this.#onDrain;\n" \
    "              this.#onDrain = null;\n" \
    "              cb();\n" \
    "            }\n" \
    "          });\n" \
    "\n" \
    "          eos(stream, err => {\n" \
    "            this.#writable = false;\n" \
    "            if (err) {\n" \
    "              destroy(stream, err);\n" \
    "            }\n" \
    "            this.#onFinished(err);\n" \
    "          });\n" \
    "        }\n" \
    "        if (stream.write(chunk, encoding)) {\n" \
    "          callback();\n" \
    "        } else {\n" \
    "          this.#onDrain = callback;\n" \
    "        }\n" \
    "      }\n" \
    "\n" \
    "      _final(callback) {\n" \
    "        this.#writeStream && this.#writeStream.end();\n" \
    "        this.#onFinish = callback;\n" \
    "      }\n" \
    "\n" \
    "      #loadReadStream() {\n" \
    "        var { createReadStream } = require(\"node:fs\");\n" \
    "\n" \
    "        var readStream = (this.#readStream = createReadStream(this.#fdPath));\n" \
    "\n" \
    "        readStream.on(\"readable\", () => {\n" \
    "          if (this.#onReadable) {\n" \
    "            const cb = this.#onReadable;\n" \
    "            this.#onReadable = null;\n" \
    "            cb();\n" \
    "          } else {\n" \
    "            this.read();\n" \
    "          }\n" \
    "        });\n" \
    "\n" \
    "        readStream.on(\"end\", () => {\n" \
    "          this.push(null);\n" \
    "        });\n" \
    "\n" \
    "        eos(readStream, err => {\n" \
    "          this.#readable = false;\n" \
    "          if (err) {\n" \
    "            destroy(readStream, err);\n" \
    "          }\n" \
    "          this.#onFinished(err);\n" \
    "        });\n" \
    "        return readStream;\n" \
    "      }\n" \
    "\n" \
    "      _read() {\n" \
    "        var stream = this.#readStream;\n" \
    "        if (!stream) {\n" \
    "          stream = this.#loadReadStream();\n" \
    "        }\n" \
    "\n" \
    "        while (true) {\n" \
    "          const buf = stream.read();\n" \
    "          if (buf === null || !this.push(buf)) {\n" \
    "            return;\n" \
    "          }\n" \
    "        }\n" \
    "      }\n" \
    "    };\n" \
    "    return new StdioWriteStream(fd_);\n" \
    "  }\n" \
    "\n" \
    "  var { EventEmitter } = require(\"node:events\");\n" \
    "\n" \
    "  function isFastEncoding(encoding) {\n" \
    "    if (!encoding) return true;\n" \
    "\n" \
    "    var normalied = encoding.toLowerCase();\n" \
    "    return normalied === \"utf8\" || normalied === \"utf-8\" || normalied === \"buffer\" || normalied === \"binary\";\n" \
    "  }\n" \
    "\n" \
    "  var FastStdioWriteStream = class StdioWriteStream extends EventEmitter {\n" \
    "    #fd;\n" \
    "    #innerStream;\n" \
    "    #writer;\n" \
    "    #isTTY;\n" \
    "\n" \
    "    bytesWritten = 0;\n" \
    "\n" \
    "    setDefaultEncoding(encoding) {\n" \
    "      if (this.#innerStream || !isFastEncoding(encoding)) {\n" \
    "        this.#ensureInnerStream();\n" \
    "        return this.#innerStream.setDefaultEncoding(encoding);\n" \
    "      }\n" \
    "    }\n" \
    "\n" \
    "    #createWriter() {\n" \
    "      switch (this.#fd) {\n" \
    "        case 1: {\n" \
    "          var writer = Bun.stdout.writer({ highWaterMark: 0 });\n" \
    "          writer.unref();\n" \
    "          return writer;\n" \
    "        }\n" \
    "\n" \
    "        case 2: {\n" \
    "          var writer = Bun.stderr.writer({ highWaterMark: 0 });\n" \
    "          writer.unref();\n" \
    "          return writer;\n" \
    "        }\n" \
    "        default: {\n" \
    "          throw new Error(\"Unsupported writer\");\n" \
    "        }\n" \
    "      }\n" \
    "    }\n" \
    "\n" \
    "    #getWriter() {\n" \
    "      return (this.#writer ??= this.#createWriter());\n" \
    "    }\n" \
    "\n" \
    "    constructor(fd_) {\n" \
    "      super();\n" \
    "      this.#fd = fd_;\n" \
    "    }\n" \
    "\n" \
    "    get fd() {\n" \
    "      return this.#fd;\n" \
    "    }\n" \
    "\n" \
    "    get isTTY() {\n" \
    "      return (this.#isTTY ??= require(\"node:tty\").isatty(this.#fd));\n" \
    "    }\n" \
    "\n" \
    "    ref() {\n" \
    "      this.#getWriter().ref();\n" \
    "    }\n" \
    "\n" \
    "    unref() {\n" \
    "      this.#getWriter().unref();\n" \
    "    }\n" \
    "\n" \
    "    on(event, listener) {\n" \
    "      if (event === \"close\" || event === \"finish\") {\n" \
    "        this.#ensureInnerStream();\n" \
    "        return this.#innerStream.on(event, listener);\n" \
    "      }\n" \
    "\n" \
    "      if (event === \"drain\") {\n" \
    "        return super.on(\"drain\", listener);\n" \
    "      }\n" \
    "\n" \
    "      if (event === \"error\") {\n" \
    "        return super.on(\"error\", listener);\n" \
    "      }\n" \
    "\n" \
    "      return super.on(event, listener);\n" \
    "    }\n" \
    "\n" \
    "    get _writableState() {\n" \
    "      this.#ensureInnerStream();\n" \
    "      return this.#innerStream._writableState;\n" \
    "    }\n" \
    "\n" \
    "    get _readableState() {\n" \
    "      this.#ensureInnerStream();\n" \
    "      return this.#innerStream._readableState;\n" \
    "    }\n" \
    "\n" \
    "    pipe(destination) {\n" \
    "      this.#ensureInnerStream();\n" \
    "      return this.#innerStream.pipe(destination);\n" \
    "    }\n" \
    "\n" \
    "    unpipe(destination) {\n" \
    "      this.#ensureInnerStream();\n" \
    "      return this.#innerStream.unpipe(destination);\n" \
    "    }\n" \
    "\n" \
    "    #ensureInnerStream() {\n" \
    "      if (this.#innerStream) return;\n" \
    "      this.#innerStream = createStdioWriteStream(this.#fd);\n" \
    "      const events = this.eventNames();\n" \
    "      for (const event of events) {\n" \
    "        this.#innerStream.on(event, (...args) => {\n" \
    "          this.emit(event, ...args);\n" \
    "        });\n" \
    "      }\n" \
    "    }\n" \
    "\n" \
    "    #write1(chunk) {\n" \
    "      var writer = this.#getWriter();\n" \
    "      const writeResult = writer.write(chunk);\n" \
    "      this.bytesWritten += writeResult;\n" \
    "      const flushResult = writer.flush(false);\n" \
    "      return !!(writeResult || flushResult);\n" \
    "    }\n" \
    "\n" \
    "    #writeWithEncoding(chunk, encoding) {\n" \
    "      if (!isFastEncoding(encoding)) {\n" \
    "        this.#ensureInnerStream();\n" \
    "        return this.#innerStream.write(chunk, encoding);\n" \
    "      }\n" \
    "\n" \
    "      return this.#write1(chunk);\n" \
    "    }\n" \
    "\n" \
    "    #performCallback(cb, err) {\n" \
    "      if (err) {\n" \
    "        this.emit(\"error\", err);\n" \
    "      }\n" \
    "\n" \
    "      try {\n" \
    "        cb(err ? err : null);\n" \
    "      } catch (err2) {\n" \
    "        this.emit(\"error\", err2);\n" \
    "      }\n" \
    "    }\n" \
    "\n" \
    "    #writeWithCallbackAndEncoding(chunk, encoding, callback) {\n" \
    "      if (!isFastEncoding(encoding)) {\n" \
    "        this.#ensureInnerStream();\n" \
    "        return this.#innerStream.write(chunk, encoding, callback);\n" \
    "      }\n" \
    "\n" \
    "      var writer = this.#getWriter();\n" \
    "      const writeResult = writer.write(chunk);\n" \
    "      const flushResult = writer.flush(true);\n" \
    "      if (flushResult?.then) {\n" \
    "        flushResult.then(\n" \
    "          () => {\n" \
    "            this.#performCallback(callback);\n" \
    "            this.emit(\"drain\");\n" \
    "          },\n" \
    "          err => this.#performCallback(callback, err),\n" \
    "        );\n" \
    "        return false;\n" \
    "      }\n" \
    "\n" \
    "      queueMicrotask(() => {\n" \
    "        this.#performCallback(callback);\n" \
    "      });\n" \
    "\n" \
    "      return !!(writeResult || flushResult);\n" \
    "    }\n" \
    "\n" \
    "    write(chunk, encoding, callback) {\n" \
    "      const result = this._write(chunk, encoding, callback);\n" \
    "\n" \
    "      if (result) {\n" \
    "        this.emit(\"drain\");\n" \
    "      }\n" \
    "\n" \
    "      return result;\n" \
    "    }\n" \
    "\n" \
    "    get hasColors() {\n" \
    "      return Bun.tty[this.#fd].hasColors;\n" \
    "    }\n" \
    "\n" \
    "    _write(chunk, encoding, callback) {\n" \
    "      var inner = this.#innerStream;\n" \
    "      if (inner) {\n" \
    "        return inner.write(chunk, encoding, callback);\n" \
    "      }\n" \
    "\n" \
    "      switch (arguments.length) {\n" \
    "        case 0: {\n" \
    "          var error = new Error(\"Invalid arguments\");\n" \
    "          error.code = \"ERR_INVALID_ARG_TYPE\";\n" \
    "          throw error;\n" \
    "        }\n" \
    "        case 1: {\n" \
    "          return this.#write1(chunk);\n" \
    "        }\n" \
    "        case 2: {\n" \
    "          if (typeof encoding === \"function\") {\n" \
    "            return this.#writeWithCallbackAndEncoding(chunk, \"\", encoding);\n" \
    "          } else if (typeof encoding === \"string\") {\n" \
    "            return this.#writeWithEncoding(chunk, encoding);\n" \
    "          }\n" \
    "        }\n" \
    "        default: {\n" \
    "          if (\n" \
    "            (typeof encoding !== \"undefined\" && typeof encoding !== \"string\") ||\n" \
    "            (typeof callback !== \"undefined\" && typeof callback !== \"function\")\n" \
    "          ) {\n" \
    "            var error = new Error(\"Invalid arguments\");\n" \
    "            error.code = \"ERR_INVALID_ARG_TYPE\";\n" \
    "            throw error;\n" \
    "          }\n" \
    "\n" \
    "          if (typeof callback === \"undefined\") {\n" \
    "            return this.#writeWithEncoding(chunk, encoding);\n" \
    "          }\n" \
    "\n" \
    "          return this.#writeWithCallbackAndEncoding(chunk, encoding, callback);\n" \
    "        }\n" \
    "      }\n" \
    "    }\n" \
    "\n" \
    "    destroy() {\n" \
    "      return this;\n" \
    "    }\n" \
    "\n" \
    "    end() {\n" \
    "      return this;\n" \
    "    }\n" \
    "  };\n" \
    "\n" \
    "  return new FastStdioWriteStream(fd_);\n" \
    "})\n" \
;

const JSC::ConstructAbility s_processObjectInternalsGetStdinStreamCodeConstructAbility = JSC::ConstructAbility::CannotConstruct;
const JSC::ConstructorKind s_processObjectInternalsGetStdinStreamCodeConstructorKind = JSC::ConstructorKind::None;
const JSC::ImplementationVisibility s_processObjectInternalsGetStdinStreamCodeImplementationVisibility = JSC::ImplementationVisibility::Public;
const int s_processObjectInternalsGetStdinStreamCodeLength = 4305;
static const JSC::Intrinsic s_processObjectInternalsGetStdinStreamCodeIntrinsic = JSC::NoIntrinsic;
const char* const s_processObjectInternalsGetStdinStreamCode =
    "(function (fd_, rawRequire, Bun) {\n" \
    "  var module = { path: \"node:process\", require: rawRequire };\n" \
    "  var require = path => module.require(path);\n" \
    "\n" \
    "  var { Duplex, eos, destroy } = require(\"node:stream\");\n" \
    "\n" \
    "  var StdinStream = class StdinStream extends Duplex {\n" \
    "    #reader;\n" \
    "    //\n" \
    "\n" \
    "    #readRef;\n" \
    "    #writeStream;\n" \
    "\n" \
    "    #readable = true;\n" \
    "    #unrefOnRead = false;\n" \
    "    #writable = true;\n" \
    "\n" \
    "    #onFinish;\n" \
    "    #onClose;\n" \
    "    #onDrain;\n" \
    "\n" \
    "    get isTTY() {\n" \
    "      return require(\"tty\").isatty(fd_);\n" \
    "    }\n" \
    "\n" \
    "    get fd() {\n" \
    "      return fd_;\n" \
    "    }\n" \
    "\n" \
    "    constructor() {\n" \
    "      super({ readable: true, writable: true });\n" \
    "    }\n" \
    "\n" \
    "    #onFinished(err) {\n" \
    "      const cb = this.#onClose;\n" \
    "      this.#onClose = null;\n" \
    "\n" \
    "      if (cb) {\n" \
    "        cb(err);\n" \
    "      } else if (err) {\n" \
    "        this.destroy(err);\n" \
    "      } else if (!this.#readable && !this.#writable) {\n" \
    "        this.destroy();\n" \
    "      }\n" \
    "    }\n" \
    "\n" \
    "    _destroy(err, callback) {\n" \
    "      if (!err && this.#onClose !== null) {\n" \
    "        var AbortError = class AbortError extends Error {\n" \
    "          constructor(message = \"The operation was aborted\", options = void 0) {\n" \
    "            if (options !== void 0 && typeof options !== \"object\") {\n" \
    "              throw new Error(`Invalid AbortError options:\\n" \
    "\\n" \
    "${JSON.stringify(options, null, 2)}`);\n" \
    "            }\n" \
    "            super(message, options);\n" \
    "            this.code = \"ABORT_ERR\";\n" \
    "            this.name = \"AbortError\";\n" \
    "          }\n" \
    "        };\n" \
    "        err = new AbortError();\n" \
    "      }\n" \
    "\n" \
    "      if (this.#onClose === null) {\n" \
    "        callback(err);\n" \
    "      } else {\n" \
    "        this.#onClose = callback;\n" \
    "        if (this.#writeStream) destroy(this.#writeStream, err);\n" \
    "      }\n" \
    "    }\n" \
    "\n" \
    "    setRawMode(mode) {}\n" \
    "    on(name, callback) {\n" \
    "      //\n" \
    "      //\n" \
    "      //\n" \
    "      //\n" \
    "      //\n" \
    "      //\n" \
    "      //\n" \
    "      //\n" \
    "      //\n" \
    "      if (name === \"readable\") {\n" \
    "        this.ref();\n" \
    "        this.#unrefOnRead = true;\n" \
    "      }\n" \
    "      return super.on(name, callback);\n" \
    "    }\n" \
    "\n" \
    "    pause() {\n" \
    "      this.unref();\n" \
    "      return super.pause();\n" \
    "    }\n" \
    "\n" \
    "    resume() {\n" \
    "      this.ref();\n" \
    "      return super.resume();\n" \
    "    }\n" \
    "\n" \
    "    ref() {\n" \
    "      this.#reader ??= Bun.stdin.stream().getReader();\n" \
    "      this.#readRef ??= setInterval(() => {}, 1 << 30);\n" \
    "    }\n" \
    "\n" \
    "    unref() {\n" \
    "      if (this.#readRef) {\n" \
    "        clearInterval(this.#readRef);\n" \
    "        this.#readRef = null;\n" \
    "      }\n" \
    "    }\n" \
    "\n" \
    "    async #readInternal() {\n" \
    "      try {\n" \
    "        var done, value;\n" \
    "        const read = this.#reader.readMany();\n" \
    "\n" \
    "        //\n" \
    "        if (!read?.then) {\n" \
    "          ({ done, value } = read);\n" \
    "        } else {\n" \
    "          ({ done, value } = await read);\n" \
    "        }\n" \
    "\n" \
    "        if (!done) {\n" \
    "          this.push(value[0]);\n" \
    "\n" \
    "          //\n" \
    "          const length = value.length;\n" \
    "          for (let i = 1; i < length; i++) {\n" \
    "            this.push(value[i]);\n" \
    "          }\n" \
    "        } else {\n" \
    "          this.push(null);\n" \
    "          this.pause();\n" \
    "          this.#readable = false;\n" \
    "          this.#onFinished();\n" \
    "        }\n" \
    "      } catch (err) {\n" \
    "        this.#readable = false;\n" \
    "        this.#onFinished(err);\n" \
    "      }\n" \
    "    }\n" \
    "\n" \
    "    _read(size) {\n" \
    "      if (this.#unrefOnRead) {\n" \
    "        this.unref();\n" \
    "        this.#unrefOnRead = false;\n" \
    "      }\n" \
    "      this.#readInternal();\n" \
    "    }\n" \
    "\n" \
    "    #constructWriteStream() {\n" \
    "      var { createWriteStream } = require(\"node:fs\");\n" \
    "      var writeStream = (this.#writeStream = createWriteStream(\"/dev/fd/0\"));\n" \
    "\n" \
    "      writeStream.on(\"finish\", () => {\n" \
    "        if (this.#onFinish) {\n" \
    "          const cb = this.#onFinish;\n" \
    "          this.#onFinish = null;\n" \
    "          cb();\n" \
    "        }\n" \
    "      });\n" \
    "\n" \
    "      writeStream.on(\"drain\", () => {\n" \
    "        if (this.#onDrain) {\n" \
    "          const cb = this.#onDrain;\n" \
    "          this.#onDrain = null;\n" \
    "          cb();\n" \
    "        }\n" \
    "      });\n" \
    "\n" \
    "      eos(writeStream, err => {\n" \
    "        this.#writable = false;\n" \
    "        if (err) {\n" \
    "          destroy(writeStream, err);\n" \
    "        }\n" \
    "        this.#onFinished(err);\n" \
    "      });\n" \
    "\n" \
    "      return writeStream;\n" \
    "    }\n" \
    "\n" \
    "    _write(chunk, encoding, callback) {\n" \
    "      var writeStream = this.#writeStream;\n" \
    "      if (!writeStream) {\n" \
    "        writeStream = this.#constructWriteStream();\n" \
    "      }\n" \
    "\n" \
    "      if (writeStream.write(chunk, encoding)) {\n" \
    "        callback();\n" \
    "      } else {\n" \
    "        this.#onDrain = callback;\n" \
    "      }\n" \
    "    }\n" \
    "\n" \
    "    _final(callback) {\n" \
    "      this.#writeStream.end();\n" \
    "      this.#onFinish = (...args) => callback(...args);\n" \
    "    }\n" \
    "  };\n" \
    "\n" \
    "  return new StdinStream();\n" \
    "})\n" \
;


#define DEFINE_BUILTIN_GENERATOR(codeName, functionName, overriddenName, argumentCount) \
JSC::FunctionExecutable* codeName##Generator(JSC::VM& vm) \
{\
    JSVMClientData* clientData = static_cast<JSVMClientData*>(vm.clientData); \
    return clientData->builtinFunctions().processObjectInternalsBuiltins().codeName##Executable()->link(vm, nullptr, clientData->builtinFunctions().processObjectInternalsBuiltins().codeName##Source(), std::nullopt, s_##codeName##Intrinsic); \
}
WEBCORE_FOREACH_PROCESSOBJECTINTERNALS_BUILTIN_CODE(DEFINE_BUILTIN_GENERATOR)
#undef DEFINE_BUILTIN_GENERATOR


} // namespace WebCore
