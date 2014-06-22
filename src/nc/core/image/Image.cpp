/* The file is part of Snowman decompiler.             */
/* See doc/licenses.txt for the licensing information. */

//
// SmartDec decompiler - SmartDec is a native code to C/C++ decompiler
// Copyright (C) 2015 Alexander Chernov, Katerina Troshina, Yegor Derevenets,
// Alexander Fokin, Sergey Levin, Leonid Tsvetkov
//
// This file is part of SmartDec decompiler.
//
// SmartDec decompiler is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// SmartDec decompiler is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with SmartDec decompiler.  If not, see <http://www.gnu.org/licenses/>.
//

#include "Image.h"

#include <nc/common/make_unique.h>

#include <nc/core/arch/ArchitectureRepository.h>
#include <nc/core/image/Image.h>
#include <nc/core/mangling/Demangler.h>
#include <nc/core/mangling/BundledDemangler.h>

#include "Sections.h"
#include "Symbols.h"

namespace nc { namespace core { namespace image {

Image::Image():
    architecture_(NULL),
    sections_(new Sections()),
    symbols_(new Symbols()),
    demangler_(new mangling::BundledDemangler())
{}

Image::~Image() {}

void Image::setArchitecture(const arch::Architecture *architecture) {
    assert(architecture != NULL);
    assert(architecture_ == NULL && "Can't set the architecture twice.");

    architecture_ = architecture;
}

void Image::setArchitecture(const QString &name) {
    setArchitecture(arch::ArchitectureRepository::instance()->getArchitecture(name));
}

void Image::setDemangler(std::unique_ptr<mangling::Demangler> demangler) {
    assert(demangler != NULL);

    demangler_ = std::move(demangler);
}

void Image::setDemangler(const QString &) {
    /* Currently only the bundled demangler is supported. */
}

}}} // namespace nc::core::image

/* vim:set et sts=4 sw=4: */
